// Copyright 2024

#include "alg.h"

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int leftVal = arr[left];
            int leftCount = 1;
            while (left + leftCount <= right && arr[left + leftCount] == leftVal) {
                leftCount++;
            }
            int rightVal = arr[right];
            int rightCount = 1;
            while (right - rightCount >= left && arr[right - rightCount] == rightVal) {
                rightCount++;
            }
            count += leftCount * rightCount;
            left += leftCount;
            right -= rightCount;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int binarySearchCount(int *arr, int start, int end, int target) {
    if (start > end) return 0;

    int left = start;
    int right = end;
    int firstIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            firstIndex = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (firstIndex == -1) return 0;

    left = firstIndex;
    right = end;
    int lastIndex = firstIndex;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            lastIndex = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return lastIndex - firstIndex + 1;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        if (target < arr[i]) {
            continue;
        }
        int foundCount = binarySearchCount(arr, i + 1, len - 1, target);
        count += foundCount;
    }
    return count;
}
