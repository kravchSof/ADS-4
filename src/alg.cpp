// Copyright 2021 NNTU-CS

#include <utility>

void QuickSort(int arr[], int p, int r) {
  int i, j;
  int x;
  i = p;
  j = r;
  x = arr[(i + j) / 2];
  do {
    while (arr[i] < x) i++;
    while (arr[j] > x) j--;
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  } while (i <= j);
  if (j > p) QuickSort(arr, p, j);
  if (i < r) QuickSort(arr, i, r);
}

int countPairs1(int *arr, int len, int value) {
  int res = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (i != j && arr[i] + arr[j] == value) {
        res++;
      }
    }
  }
  return res / 2;
}
int countPairs2(int *arr, int len, int value) {
  int res = 0;
  QuickSort(arr, 0, len - 1);
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[j] + arr[i] < value) break;
      if (arr[i] + arr[j] == value) {
        res++;
      }
    }
  }
  return res;
}
int countPairs3(int *arr, int len, int value) {
  int res = 0;
  QuickSort(arr, 0, len - 1);

  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int l = i + 1;
    int r = len - 1;

    int leftr = -1;
    while (l <= r) {
      int x = (l + r) / 2;
      if (arr[x] == target) {
        leftr = x;
        r = x - 1;
      } else if (arr[x] < target) {
        l = x + 1;
      } else {
        r = x - 1;
      }
    }
    if (leftr == -1) continue;

    int rightr = -1;
    l = i + 1;
    r = len - 1;
    while (l <= r) {
      int x = (l + r) / 2;
      if (arr[x] == target) {
        rightr = x;
        l = x + 1;
      } else if (arr[x] < target) {
        l = x + 1;
      } else {
        r = x - 1;
      }
    }
    res += (rightr - leftr + 1);
  }
  return res;
}
