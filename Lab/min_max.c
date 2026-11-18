#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int low, int high) {
    struct MinMax result, left, right;
    int mid;

    // If there is only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // If there are more than two elements
    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}