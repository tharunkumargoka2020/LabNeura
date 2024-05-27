#include "algorithms/sorting.h"
#include <vector>

Sorting::Sorting(std::vector<int> a){
    data = a;
    n = data.size();
}
void Sorting::selection(){
    for (int i=0; i<n-1; i++){
        int minIdx = i;
        for (int j = i+1; j<n; j++){
            if (data[j]<data[minIdx])
                minIdx = j;
        }
        std::swap(data[minIdx],data[i]);
    }
}

void Sorting::insertion(){
    for (int i=1; i<n; i++){
        int current = data[i];
        int j = i-1;
        while(j>=0 && data[j]>current){
            data[j+1] = data[j];
            j = j-1;
        }
        data[j+1] = current;
    }
}

void Sorting::bubble(){
    for (int i=0; i<n-1; i++){
        bool swapped = false;
        for (int j=0; j<n-i-1; j++){
            if (data[j]>data[j+1])
                std::swap(data[j],data[j+1]);
                swapped = true;
        }
        if (!swapped)
            break;
    }
}
void Sorting::merge(){
    merge_sort(data, 0, n);
}

void Sorting::merge_sort(std::vector<int>& data, int lower, int upper){
    if (lower >= upper)
        return;
    int mid = lower + (upper-lower)/2;
    merge_sort(data, lower, mid);
    merge_sort(data, mid+1, upper);
    int n1 = mid - lower + 1;
    int n2 = upper - mid;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i=0; i<n1; i++){
        left[i] =(data[lower+i]);
    }
    for (int j=0; j<n2; j++){
        right[j] = (data[mid+1+j]);
    }

    int i=0;
    int j=0;
    int k = lower;

    while (i<n1 && j<n2){
        if (left[i]<=right[j]){
            data[k] = left[i];
            k+=1;
            i+=1;
        }
        else{
            data[k] = right[j];
            k+=1;
            j+=1;
        }
    }

    while (i<n1){
        data[k]=left[i];
        k+=1;
        i+=1;
    }

    while (j<n2){
        data[k] = right[j];
        k+=1;
        j+=1;
    }
}

void Sorting::quick(){
    quick_sort(data, 0, n);
}

void Sorting::quick_sort(std::vector<int>& a, int lower, int upper){
    if (lower<upper){
        int pi = partition(a, lower, upper);
        quick_sort(a,lower, pi-1);
        quick_sort(a, pi+1, upper);
    }
}

int Sorting::partition(std::vector<int>& a, int lower, int upper){
    int pivot = a[upper];
    int i = lower-1;
    for (int j=lower; j<=upper-1; j++){
        if (a[j]<=pivot){
            i = i+1;
            std::swap(a[j],a[i]);
        }
    }
    std::swap(a[i+1],a[upper]);
    return i+1;
}

void Sorting::setData(std::vector<int> a){
    data = a;
}

std::vector<int> Sorting::getData(){
    return data;
}