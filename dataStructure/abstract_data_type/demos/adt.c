#include <stdio.h>
#include <stdlib.h>

struct Array {
  int A[20];
  int size;
  int length;
};

void Display(struct Array arr) {
  printf("Elements are:\n");
  for (int i = 0; i < arr.length; i++) {
    printf("%d ", arr.A[i]);
  }
  printf("\n");
}

void Append(struct Array *arr, int x) {
  if (arr->length < arr->size) {
    arr->A[arr->length] = x;
    arr->length++;
  }
}

void Insert(struct Array *arr, int index, int x) {
  if (index >= 0 && index <= arr->length) {
    for (int i = arr->length; i > index; i--) {
      arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
  }
}

void Delete(struct Array *arr, int index) {
  if (index >= 0 && index < arr->length) {
    for (int i = index; i < arr->length - 1; i++) {
      arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
  }
}

void Swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int LinearSearch(struct Array arr, int key) {
  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] == key) {
      return i;
    }
  }
  return -1;
}

int LinearSearchWithTransposition(struct Array *arr, int key) {
  for (int i = 0; i < arr->length; i++) {
    if (arr->A[i] == key) {
      Swap(&arr->A[i], &arr->A[i - 1]);
      return i - 1;
    }
  }
  return -1;
}

int LinearSearchWithMoveHead(struct Array *arr, int key) {
  for (int i = 0; i < arr->length; i++) {
    if (arr->A[i] == key) {
      Swap(&arr->A[i], &arr->A[0]);
      return i - 1;
    }
  }
  return -1;
}

int BinarySearch(struct Array arr, int key) {
  int low = 0;
  int high = arr.length - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (key == arr.A[mid]) {
      return mid;
    } else if (key < arr.A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int BinarySearchRecursive(struct Array arr, int low, int high, int key) {
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  if (key == arr.A[mid]) {
    return mid;
  } else if (key < arr.A[mid]) {
    return BinarySearchRecursive(arr, low, mid - 1, key);
  } else {
    return BinarySearchRecursive(arr, mid + 1, high, key);
  }
}



int main() {
  struct Array arr={{2,3,4,5,6}, 20, 5}; // Initialize the array with size 10 and length 0

  printf("%d\n", LinearSearch(arr, 4)); // Search for the element 4 in the array

 // display the array
  Display(arr);


  return 0;
}