#include "implot.h"
#include "implot_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <charconv>


#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> 

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}


const std::vector<double> soc = { 1, 0.979455857856746, 0.959189339255969, 0.939200444197668, 0.919211549139367, 0.899222654081066, 0.849250416435314, 0.799278178789561, 0.749305941143809, 0.699611327040533, 0.649639089394781, 0.599666851749028, 0.549694614103276, 0.499722376457524, 0.449750138811771, 0.399777901166019, 0.349528039977790, 0.299555802332038, 0.249583564686285, 0.199611327040533, 0.149639089394781, 0.0999444752915047, 0.0796779566907274, 0.0599666851749028, 0.0399777901166019, 0.0199888950583009, 0 };
const std::vector<double> ocv = { 4.20059028171202, 4.16445653203492, 4.14012975447597, 4.11793510998830, 4.09733423488953, 4.07980521404167, 4.03471248342643, 3.98866453343482, 3.93119212338236, 3.87352922950037, 3.83465671865652, 3.79917203042368, 3.78245430078528, 3.75949626563702, 3.73467566916230, 3.71464781193304, 3.68808193297151, 3.66808619543555, 3.63583981697506, 3.59994730963900, 3.57430273447701, 3.54612302249662, 3.49076110025690, 3.42024513850162, 3.31767959768643, 3.17747531909001, 3.01476509201849 };
const std::vector<double> r0 = { 0.00719146897428723, 0.00741850900708751, 0.00743403420495271, 0.00748776198313241, 0.00721529818378370, 0.00716371327631248, 0.00668149676770256, 0.00685037715211540, 0.00687085756080030, 0.00704421277070143, 0.00658139870114716, 0.00602943743802638, 0.00604826154895946, 0.00633867560153846, 0.00649461462617092, 0.00654641416094327, 0.00692275952370252, 0.00727251528016254, 0.00742656026487787, 0.00789437433539946, 0.0111292432537967, 0.0153515136996802, 0.0200853634227497, 0.0237805732556751, 0.0300469269478585, 0.0399182691648787, 0.0656593972614554 };
const std::vector<double> r1 = { 0.00518399051058848, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047 };
const std::vector<double> r2 = { 0.00437254212211296, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237 };
const std::vector<double> r3 = { 0.00588621223605553, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064 };
const std::vector<double> t1 = { 9.86264106192937, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048 };
const std::vector<double> t2 = { 200.107655784865, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401 };
const std::vector<double> t3 = { 637.560091248790, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017 };
const double bat_ah = 10.00555556;

struct Params {
    std::vector<double> soc;
    std::vector<double> ocv;
    std::vector<double> r0;
    std::vector<double> r1;
    std::vector<double> r2;
    std::vector<double> r3;
    std::vector<double> t1;
    std::vector<double> t2;
    std::vector<double> t3;
    double bat_ah;
    int ms;

    Params(std::vector<double> soc_, std::vector<double> ocv_, std::vector<double> r0_,
        std::vector<double> r1_, std::vector<double> r2_, std::vector<double> r3_,
        std::vector<double> t1_, std::vector<double> t2_, std::vector<double> t3_,
        double bat_ah_, int ms_) : soc(soc_), ocv(ocv_), r0(r0_), r1(r1_), r2(r2_), r3(r3_),
        t1(t1_), t2(t2_), t3(t3_), bat_ah(bat_ah_), ms(ms_) {}
};

class Emu {
public:
    Params params;
    float load_sensitivity;
    int max_vectorsize;
    double ams;
    double soc;
    double load_time;
    bool c_load = false;
    int counter = 0;
    std::vector<double> voltage;
    std::vector<double> time;
    std::vector<double> current;

    Emu(Params params_, float load_sensitivity_ = 0, int max_vectorsize_ = 0, float ams_percent_ = 100)
        : params(params_), load_sensitivity(load_sensitivity_), max_vectorsize(max_vectorsize_){
        ams = std::round(params.bat_ah * 3600000) * (ams_percent_ / 100);
        soc = params.soc[0];
        load_time = 0;
    }

    double param_calc(const std::vector<double>& param, int idx, double instep_percent) {
        return param[idx] - (param[idx] - param[idx + 1]) * instep_percent;
    }

    double vl_calc(float load) {
        soc = ams / std::round(params.bat_ah * 3600000);
        double abs1 = params.soc[0] - soc;
        int idx_count = 0;
        for (int i = 1; i < params.soc.size(); ++i) {
            double abs2 = std::abs(params.soc[i] - soc);
            if (abs1 < abs2)
                break;
            else {
                abs1 = abs2;
                idx_count += 1;
            }
        }
        int idx = idx_count;
        if (soc > params.soc[idx])
            idx -= 1;
        double instep_percent = (params.soc[idx] - soc) / (params.soc[idx] - params.soc[idx + 1]);
        double ocv = param_calc(params.ocv, idx, instep_percent);
        double r0 = param_calc(params.r0, idx, instep_percent);
        double r1 = param_calc(params.r1, idx, instep_percent);
        double r2 = param_calc(params.r2, idx, instep_percent);
        double r3 = param_calc(params.r3, idx, instep_percent);
        double t1 = param_calc(params.t1, idx, instep_percent);
        double t2 = param_calc(params.t2, idx, instep_percent);
        double t3 = param_calc(params.t3, idx, instep_percent);

        double tmp_load_time = load_time / (1000.0 / params.ms);

        if (c_load) { ams -= load * params.ms; }
        load_time++;

        if (c_load) {
            double u0 = load * r0;
            double u1 = load * r1 * (1 - std::exp(-tmp_load_time / t1));
            double u2 = load * r2 * (1 - std::exp(-tmp_load_time / t2));
            double u3 = load * r3 * (1 - std::exp(-tmp_load_time / t3));
            double vl = ocv - u0 - u1 - u2 - u3;
            return vl;
        }
        double u1_nl = r1 * (std::exp(-tmp_load_time / t1));
        double u2_nl = r2 * (std::exp(-tmp_load_time / t2));
        double u3_nl = r3 * (std::exp(-tmp_load_time / t3));
        double vl_nl = ocv - u1_nl - u2_nl - u3_nl;
        return vl_nl;
    }

    void check_load(float load) {
        if (c_load && load <= load_sensitivity) {
            load_time = 0;
            c_load = false;
        }
        else if (!c_load && load > load_sensitivity) {
            load_time = 0;
            c_load = true;
        }
    }

    void run(float load) {
        if (ams > 0) {
            check_load(load);
            if (max_vectorsize != 0 && time.size() > max_vectorsize) {
                time.erase(time.begin());
                voltage.erase(voltage.begin());
            }
            voltage.push_back(vl_calc(load));
            time.push_back(counter);
            current.push_back(load);
            counter++;
        }
    }
};


static void plottest(auto &sim) {
  
    ImPlot::SetNextAxesToFit();
  
    ImPlot::BeginPlot("Testplot");
    ImPlot::SetupAxes("Time", "A");
    ImPlot::PlotLine("Voltage", sim.time.data(), sim.voltage.data(), sim.time.size());
   
    ImPlot::EndPlot();
}

float param_window(auto io, auto &sim) {
    static float load = 0;
    
    ImGui::Begin("Parameters");         
    ImGui::Text("State of Charge: %.2f", sim.soc * 100);
    if (sim.time.size() > 0) { ImGui::Text("Voltage: %.4f V", sim.voltage.back()); }
    ImGui::Text("Current: %.2f A", load);
    ImGui::Text("Time/fr: %.0f ms", float(sim.params.ms));
    ImGui::Text("Time on/off load: %.2f s", float(sim.load_time / (1000 / sim.params.ms)));
    ImGui::Dummy(ImVec2(0, 20));
    ImGui::SliderFloat("Load A", &load, 0, int(sim.params.bat_ah) * 3);
    ImGui::Dummy(ImVec2(0, 10));
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    ImGui::End();
    return load;
}
 
static void windowcomps(auto io, auto &sim) {
    float load = param_window(io, sim);
    plottest(sim);
    sim.run(load);
}







int ImGuiLoop(auto &sim) {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Battery Emulator", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);

#ifdef __EMSCRIPTEN__
    ImGui_ImplGlfw_InstallEmscriptenCanvasResizeCallback("#canvas");
#endif
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

#ifdef __EMSCRIPTEN__
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!glfwWindowShouldClose(window))
#endif
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        windowcomps(io, sim);

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImPlot::DestroyContext();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

int main()
{
    int ms = 50;
    Params params(soc, ocv, r0, r1, r2, r3, t1, t2, t3, bat_ah, ms);
    Emu sim(params, 3);
    ImGuiLoop(sim);

    return 0;
}