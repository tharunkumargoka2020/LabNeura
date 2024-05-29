#pragma once

#include <vector>

class Sorting {
    public:
        Sorting(std::vector<int> a);
        void selection();
        void insertion();
        void bubble();
        void merge();
        void merge_sort(std::vector<int>& a, int lower, int upper);
        void quick();
        void quick_sort(std::vector<int>&, int lower, int upper);
        int partition(std::vector<int>& a, int lower, int upper);

        void setData(std::vector<int> a);
        std::vector<int> getData();

        int getTimeSteps();
        int getSwaps();
        int getRecursiveCalls();
    private:
        std::vector<int> data;
        int n;
        int no_timesteps;
        int no_recursive_calls;
        int no_swaps;
};