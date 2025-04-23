#include <stdio.h>

void sort(int arr[], int n) {
    int temp;
    for(int i = 0; i < n; i++) {
        int min_ind = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[min_ind] > arr[j]) {
                min_ind = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
    }
}

int find(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) return i;
    }
    return -1;
}

double calculateAverage(int arr[], int n) {
    double total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}

int findMedian(int arr[], int n) {
    sort(arr, n);
    if(n % 2 == 0) {
        return (arr[(n/2)-1] + arr[n/2]) / 2;
    }
    else {
        return arr[n/2];
    }
}

int findMode(int arr[], int n) {
    int max_count = 0;
    int mode = arr[0];
    
    for(int i = 0; i < n; i++) {
        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }
    return mode;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void reverseArray(int arr[], int n) {
    int temp;
    for(int i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}