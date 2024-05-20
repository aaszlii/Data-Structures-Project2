#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

class Timer {
private:
    time_point<steady_clock> start_time;
    time_point<steady_clock> end_time;
public:
    void start() {
        start_time = steady_clock::now();
    }

    void stop() {
        end_time = steady_clock::now();
    }

    double elapsed_milliseconds() const {
        return duration<double, std::milli>(end_time - start_time).count();
    }
};
