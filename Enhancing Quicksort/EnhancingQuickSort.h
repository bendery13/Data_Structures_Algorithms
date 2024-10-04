#include <iostream>
using namespace std;

void sampleArray(int arr[]);
void populateRandoms(int arr1[], int arr2[], int arr3[], int arr4[], int arr5[]);
void populateSorted(int arr1[], int arr2[], int arr3[], int arr4[], int arr5[]);
void quickSort(int arr[], int  start, int end);
int partition(int arr[], int  start, int end);

int middlePartition(int arr[], int start, int end);
void middleQuickSort(int arr[], int start, int end);

int randomPartition(int arr[], int start, int end);
void randomQuickSort(int arr[], int  start, int end);

void quickSort(int arr[], int start, int end){
    while (start < end) {  
        if (end <= start) {
            return;
        }

        int pivot = partition(arr, start, end);

        if (pivot - start < end - pivot) {
            quickSort(arr, start, pivot - 1);
            start = pivot + 1; 
        } else {
            quickSort(arr, pivot + 1, end);
            end = pivot - 1; 
        }
    }
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void middleQuickSort(int arr[], int start, int end) {
    while (start < end) {
        // Partition the array and get pivot index
        int pivot = middlePartition(arr, start, end);

        // Recursively sort the smaller partition first
        if (pivot - start < end - pivot) {
            // Sort the left partition recursively
            middleQuickSort(arr, start, pivot - 1);
            // Update start to move to the larger right partition
            start = pivot + 1;
        } else {
            // Sort the right partition recursively
            middleQuickSort(arr, pivot + 1, end);
            // Update end to move to the larger left partition
            end = pivot - 1;
        }
    }
}

int middlePartition(int arr[], int start, int end) {
    // Calculate the middle index
    int mid = start + (end - start) / 2;
    // Swap the middle element with the last element to use it as pivot
    swap(arr[mid], arr[end]);
    int pivot = arr[end];  // Now, pivot is at the end
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot in its correct position
    i++;
    swap(arr[i], arr[end]);
    return i;
}


void randomQuickSort(int arr[], int start, int end) {
    while (start < end) {
        // Partition the array and get the pivot index
        int pivot = randomPartition(arr, start, end);

        // Sort the smaller partition first to minimize recursion depth
        if (pivot - start < end - pivot) {
            // Sort left partition recursively
            randomQuickSort(arr, start, pivot - 1);
            // Update start for the right partition
            start = pivot + 1;
        } else {
            // Sort right partition recursively
            randomQuickSort(arr, pivot + 1, end);
            // Update end for the left partition
            end = pivot - 1;
        }
    }
}

int randomPartition(int arr[], int start, int end) {
    // Select a random pivot index between start and end
    int randomIndex = start + rand() % (end - start + 1);
    
    // Swap the random pivot with the last element
    swap(arr[randomIndex], arr[end]);

    // Proceed with the normal partition process
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element back to its correct position
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void populateRandoms(int arr1[], int arr2[], int arr3[], int arr4[], int arr5[]){
    srand(time(0)); 
    for (int i = 0; i < 100000; i++){
        arr1[i] = (rand() % 1000000) + 1;
    }
    for (int i = 0; i < 200000; i++){
        arr2[i] = (rand() % 1000000) + 1;
    }
    for (int i = 0; i < 300000; i++){
        arr3[i] = (rand() % 1000000) + 1;
    }
    for (int i = 0; i < 400000; i++){
        arr4[i] = (rand() % 1000000) + 1;
    }
    for (int i = 0; i < 500000; i++){
        arr5[i] = (rand() % 1000000) + 1;
    }
}
void populateSorted(int arr1[], int arr2[], int arr3[], int arr4[], int arr5[]){
        for (int i = 0; i < 100000; i++){
        arr1[i] = i;
    }
    for (int i = 0; i < 200000; i++){
        arr2[i] = i;
    }
    for (int i = 0; i < 300000; i++){
        arr3[i] = i;
    }
    for (int i = 0; i < 400000; i++){
        arr4[i] = i;
    }
    for (int i = 0; i < 500000; i++){
        arr5[i] = i;
    }
}
void sampleArray(int arr[]){
    int i;
    int size = 25;
    for (i = 0; i < size; i+= 5)
        cout << arr[i] << ", ";

    cout << " ... ";

    for (i = 1000; i < 1000 + size; i+=5)
        cout << arr[i] << ", ";

    cout << " ... ";
    
    for (i = 2500; i < 2500 + size; i+=5)
        cout << arr[i] << ", ";
    cout << endl;
}



