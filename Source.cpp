#include <iostream>
#include <vector>
#include <cmath>

const std::vector<double> soc_values = { 1, 0.979455857856746, 0.959189339255969, 0.939200444197668, 0.919211549139367, 0.899222654081066, 0.849250416435314, 0.799278178789561, 0.749305941143809, 0.699611327040533, 0.649639089394781, 0.599666851749028, 0.549694614103276, 0.499722376457524, 0.449750138811771, 0.399777901166019, 0.349528039977790, 0.299555802332038, 0.249583564686285, 0.199611327040533, 0.149639089394781, 0.0999444752915047, 0.0796779566907274, 0.0599666851749028, 0.0399777901166019, 0.0199888950583009, 0 };
const std::vector<double> ocv_values = { 4.20059028171202, 4.16445653203492, 4.14012975447597, 4.11793510998830, 4.09733423488953, 4.07980521404167, 4.03471248342643, 3.98866453343482, 3.93119212338236, 3.87352922950037, 3.83465671865652, 3.79917203042368, 3.78245430078528, 3.75949626563702, 3.73467566916230, 3.71464781193304, 3.68808193297151, 3.66808619543555, 3.63583981697506, 3.59994730963900, 3.57430273447701, 3.54612302249662, 3.49076110025690, 3.42024513850162, 3.31767959768643, 3.17747531909001, 3.01476509201849 };
const std::vector<double> r0_values = { 0.00719146897428723, 0.00741850900708751, 0.00743403420495271, 0.00748776198313241, 0.00721529818378370, 0.00716371327631248, 0.00668149676770256, 0.00685037715211540, 0.00687085756080030, 0.00704421277070143, 0.00658139870114716, 0.00602943743802638, 0.00604826154895946, 0.00633867560153846, 0.00649461462617092, 0.00654641416094327, 0.00692275952370252, 0.00727251528016254, 0.00742656026487787, 0.00789437433539946, 0.0111292432537967, 0.0153515136996802, 0.0200853634227497, 0.0237805732556751, 0.0300469269478585, 0.0399182691648787, 0.0656593972614554 };
const std::vector<double> r1_values = { 0.00518399051058848, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047, 0.00445762771780047 };
const std::vector<double> r2_values = { 0.00437254212211296, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237, 0.00402688525769237 };
const std::vector<double> r3_values = { 0.00588621223605553, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064, 0.0158863088300064 };
const std::vector<double> t1_values = { 9.86264106192937, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048, 9.05625483038048 };
const std::vector<double> t2_values = { 200.107655784865, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401, 195.293652708401 };
const std::vector<double> t3_values = { 637.560091248790, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017, 701.928692420017 };

class Params {
public:
    double bat_ah;
    double bat_load;
    double discharge_speed;
    std::vector<double> soc;
    std::vector<double> ocv;
    std::vector<double> r0;
    std::vector<double> r1;
    std::vector<double> r2;
    std::vector<double> r3;
    std::vector<double> t1;
    std::vector<double> t2;
    std::vector<double> t3;
    std::vector<int> steps;
    std::vector<int> time_steps;

    Params(double bat_ah, double bat_load) : bat_ah(bat_ah), bat_load(bat_load) {
        soc = soc_values;
        ocv = ocv_values;
        r0 = r0_values;
        r1 = r1_values;
        r2 = r2_values;
        r3 = r3_values;
        t1 = t1_values;
        t2 = t2_values;
        t3 = t3_values;
        step_calc();
    }

    void step_calc() {
        std::vector<int> res;
        std::vector<int> res_time_steps;
        double dis_speed = bat_ah / (bat_load / 3600);
        double soc_loss = (soc[0] - soc[soc.size() - 1]) / dis_speed;

        for (double soc_level : soc) {
            double temp_soc = soc[0];
            int counter = 0;
            double abs1 = std::abs(soc_level - temp_soc);

            while (temp_soc > 0) {
                double abs2 = std::abs(soc_level - temp_soc);
                if (abs2 > abs1) {
                    res.push_back(counter);
                    res_time_steps.push_back(counter - 1);
                    break;
                }
                abs1 = abs2;
                counter++;
                temp_soc -= soc_loss;
            }
        }

        for (size_t i = 0; i < res.size() - 1; i++) {
            res[i] = res[i + 1] - res[i];
        }
        res[res.size() - 1] = std::round(dis_speed) - res[res.size() - 1] + 1;

        res_time_steps.erase(res_time_steps.begin());
        res_time_steps.push_back(std::round(dis_speed));

        steps = res;
        discharge_speed = dis_speed;
        time_steps = res_time_steps;
    }
};

class Sim {
public:
    Params params;
    int discharge_time;
    int load_time;
    bool load;
    int pulses;
    int rest_time;
    std::vector<double> voltage;
    std::vector<int> time;
    std::vector<int> timeline;

    Sim(class Params param_values, int pulses = 0, int rest_time = 0) : params(params), pulses(pulses), rest_time(rest_time) {
        params = param_values;
        discharge_time = 0;
        load_time = 0;
        load = false;
        timeline_setup();
    }

    double vl_calc() {
        int idx = 0;
        for (int i = 0; i < params.time_steps.size(); ++i) {
            if (discharge_time >= params.time_steps[i]) {
                idx = i + 1;
                if (idx == params.time_steps.size()) idx--;
            }
            else {
                break;
            }
        }

        double instep_time = params.steps[idx] - (params.time_steps[idx] - discharge_time);

        double ocv = params.ocv[idx] - (params.ocv[idx] - params.ocv[idx + 1]) / params.steps[idx] * instep_time;
        double r1 = params.r1[idx] - (params.r1[idx] - params.r1[idx + 1]) / params.steps[idx] * instep_time;
        double r2 = params.r2[idx] - (params.r2[idx] - params.r2[idx + 1]) / params.steps[idx] * instep_time;
        double r3 = params.r3[idx] - (params.r3[idx] - params.r3[idx + 1]) / params.steps[idx] * instep_time;
        double t1 = params.t1[idx] - (params.t1[idx] - params.t1[idx + 1]) / params.steps[idx] * instep_time;
        double t2 = params.t2[idx] - (params.t2[idx] - params.t2[idx + 1]) / params.steps[idx] * instep_time;
        double t3 = params.t3[idx] - (params.t3[idx] - params.t3[idx + 1]) / params.steps[idx] * instep_time;
        double load_time = this->load_time;

        if (load) {
            double r0 = params.r0[idx] - (params.r0[idx] - params.r0[idx + 1]) / params.steps[idx] * instep_time;
            double load = params.bat_load;
            double u0 = load * r0;
            double u1 = load * r1 * (1 - exp(-load_time / t1));
            double u2 = load * r2 * (1 - exp(-load_time / t2));
            double u3 = load * r3 * (1 - exp(-load_time / t3));
            return ocv - u0 - u1 - u2 - u3;
        }
        else {
            double u1_nl = r1 * (exp(-load_time / t1));
            double u2_nl = r2 * (exp(-load_time / t2));
            double u3_nl = r3 * (exp(-load_time / t3));
            return ocv - u1_nl - u2_nl - u3_nl;
        }
    }

    void timeline_setup() {
        int dis_speed = round(params.bat_ah / (params.bat_load / 3600));
        if (pulses == 0) {
            for (int i = 0; i < dis_speed; ++i) {
                timeline.push_back(1);
            }
        }
        else {
            for (int i = 0; i < pulses; ++i) {
                for (int j = 0; j < rest_time; ++j) {
                    timeline.push_back(0);
                }
                for (int k = 0; k < dis_speed / pulses; ++k) {
                    timeline.push_back(1);
                }
            }
        }
    }

    void run() {
        for (int i = 0; i < timeline.size(); ++i) {
            if (timeline[i] == 1) {
                if (!load) {
                    load_time = 0;
                    load = true;
                }
                else {
                    load_time += 1;
                }
                discharge_time += 1;
            }
            else {
                if (load) {
                    load_time = 0;
                    load = false;
                }
                else {
                    load_time += 1;
                }
            }

            voltage.push_back(vl_calc());
            time.push_back(i);
        }
    }
};

int main() {
    double BAT_AH = 10.00555556;
    double BAT_LOAD = 10;
    Params params(BAT_AH, BAT_LOAD);

    Sim sim(params, 20, 5000);
    sim.run();

    return 0;
}
