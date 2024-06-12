#pragma once

#include <chrono>
#include <iostream>

class Timer {
    public:
        Timer(const std::string& func_name) : func_name(func_name), start(std::chrono::high_resolution_clock::now()) {}
        ~Timer(){
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end-start;
            std::cout << std::endl;
            std::cout << "Elapsed time of " << func_name << ": " << duration.count() << " ms" << std::endl;
        }
    private:
        std::string func_name;
        std::chrono::high_resolution_clock::time_point start;
};
