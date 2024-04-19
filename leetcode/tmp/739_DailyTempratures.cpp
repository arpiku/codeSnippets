#include"utils.h"

std::vector<int> dailyTemperatures_1(std::vector<int>& temperatures) { //This code works but exceeds time limit for long input
    std::vector<int> res;

    auto warmerDay = [&](std::vector<int>::iterator begin) -> std::vector<int>::iterator {
        return std::find_if(begin, temperatures.end(), [&](int temp) { return temp > *begin; });
    };

    for (auto itr = temperatures.begin(); itr != temperatures.end(); ++itr) {
        auto warmerItr = warmerDay(itr);
        if (warmerItr != temperatures.end()) {
            res.push_back(std::distance(itr, warmerItr));
        } else {
            res.push_back(0); // No warmer day found
        }
    }

    return res;
}
