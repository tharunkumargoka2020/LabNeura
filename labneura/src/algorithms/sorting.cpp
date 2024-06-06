#include "algorithms/sorting.h"
#include <vector>
#include <iostream>

Sorting::Sorting(std::vector<int> a){
    data = a;
    n = data.size();
    no_recursive_calls = 0;
    no_timesteps = 0;
    no_swaps = 0;
}
void Sorting::selection(){
    no_timesteps = 0;
    no_swaps = 0;
    for (int i=0; i<n-1; i++){
        int minIdx = i;
        for (int j = i+1; j<n; j++){
            if (data[j]<data[minIdx])
                minIdx = j;
            no_timesteps += 1;
        }
        std::swap(data[minIdx],data[i]);
        no_swaps += 1;
    }
}

void Sorting::insertion(){
    no_timesteps = 0;
    no_recursive_calls = 0;
    no_swaps = 0;
    bool inside;
    for (int i=1; i<n; i++){
        int current = data[i];
        int j = i-1;
        no_timesteps += 1;
        inside = false;
        while(j>=0 && data[j]>current){
            inside = true;
            no_timesteps += 1;
            data[j+1] = data[j];
            j = j-1;
        }
        if (inside){
            no_timesteps -= 1;
        }
        data[j+1] = current;
    }
}

void Sorting::bubble(){
    no_recursive_calls = 0;
    no_swaps = 0;
    no_timesteps = 0;
    for (int i=0; i<n-1; i++){
        bool swapped = false;
        for (int j=0; j<n-i-1; j++){
            no_timesteps += 1;
            if (data[j]>data[j+1]) {
                std::swap(data[j],data[j+1]);
                swapped = true;
                no_swaps += 1;
            }
        }
        if (!swapped){
            break;
        }
    }
}
void Sorting::merge(){
    no_recursive_calls = 0;
    no_swaps = 0;
    no_timesteps = 0;
    merge_sort(data, 0, n-1);
}

void Sorting::merge_sort(std::vector<int>& dt, int lower, int upper){
    no_recursive_calls += 1;
    if (lower >= upper)
        return;
    int mid = lower + (upper-lower)/2;
    merge_sort(dt, lower, mid);
    merge_sort(dt, mid+1, upper);
    int n1 = mid - lower + 1;
    int n2 = upper - mid;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i=0; i<n1; i++){
        left[i] =(dt[lower+i]);
        no_timesteps += 1;
    }
    for (int j=0; j<n2; j++){
        right[j] = (dt[mid+1+j]);
        no_timesteps += 1;
    }

    int i=0;
    int j=0;
    int k = lower;

    while (i<n1 && j<n2){
        if (left[i]<=right[j]){
            dt[k] = left[i];
            k+=1;
            i+=1;
        }
        else{
            dt[k] = right[j];
            k+=1;
            j+=1;
        }
        no_timesteps += 1;
    }

    while (i<n1){
        dt[k]=left[i];
        k+=1;
        i+=1;
        no_timesteps += 1;
    }

    while (j<n2){
        dt[k] = right[j];
        k+=1;
        j+=1;
        no_timesteps += 1;
    }
}

void Sorting::quick(){
    no_recursive_calls = 0;
    no_timesteps = 0;
    no_swaps = 0;
    quick_sort(data, 0, n-1);
}

void Sorting::quick_sort(std::vector<int>& a, int lower, int upper){
    no_recursive_calls += 1;
    if (lower<upper){
        int pivot = a[upper];
        int i = lower-1;
        for (int j=lower; j<=upper-1; j++){
            no_timesteps += 1;
            if (a[j]<=pivot){
                i += 1;
                std::swap(a[j],a[i]);
                no_swaps += 1;
            }
        }
        std::swap(a[i+1],a[upper]);
        no_swaps += 1;
        quick_sort(a,lower, i);
        quick_sort(a, i+2, upper);
    }
}

void Sorting::setData(std::vector<int> a){
    data = a;
}

std::vector<int> Sorting::getData(){
    return data;
}

int Sorting::getTimeSteps(){
    return no_timesteps;
}

int Sorting::getRecursiveCalls(){
    return no_recursive_calls;
}

int Sorting::getSwaps() {
    return no_swaps;
}