#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

int greedyAlg(int goal, int sArray[]);
int findClosestSubsetSum(int* set, int target);
void insertionSort(int a[]);

int main(){
    int setArray[20];
    int goal = 1000;
   
    srand(time(0));
    for(int i = 0; i < 20 ; i++){
        setArray[i] = (rand() % 150) + 1;
    }
    
    // For printing array
    cout << "{" ; for(int i = 0; i < 20 ; ++i){cout <<  setArray[i];  if (i < 19) {cout << ", ";}} cout << "}" << endl;

    auto start = chrono :: high_resolution_clock :: now();
    int bruteForce = findClosestSubsetSum(setArray, goal);
    auto stop = chrono :: high_resolution_clock :: now();
    chrono::duration<double> BFtime = stop - start;

    auto begin = chrono :: high_resolution_clock :: now();
    int greedy = greedyAlg(goal, setArray);
    auto end = chrono :: high_resolution_clock :: now();
    chrono::duration<double> Greedytime = end - begin;

    insertionSort(setArray);
    

    cout << "Closest using Brute Force: " << bruteForce << endl;
    cout << "Brute Force took " << BFtime.count() * 1000000000 << " nanoseconds" << endl;
    cout << "The greedy algorithm found the closest to be: " << greedy << endl;
    cout << "Greedy Algorithm took " << Greedytime.count()* 1000000000 << " nanoseconds" << endl;


    return 0;
}


int findClosestSubsetSum(int* set, int target) {
    unsigned int set_size = pow(2, 20);
    int closest = 0;

    for (int counter = 0; counter < set_size; ++counter) {
        int current_sum = 0;

        // Calculate sum of the current subset
        for (int j = 0; j < 20; ++j) {
            if (counter & (1 << j)) {
                current_sum += set[j];
            }
        }
        // Update the closest sum if current_sum is better and <= target
        if (current_sum <= target && current_sum > closest) {
            closest = current_sum;
        }
    }
    return closest;
}


int greedyAlg(int goal, int sArray[]){
    int sum = 0;
    for(int i = 19; i > 0; --i){
        if ((sum + sArray[i]) <= goal){
            sum += sArray[i];
        }
        else{
            break;
        }
    }
    return sum;
}

void insertionSort(int a[]) {
    for (int i = 1; i < 20; ++i) {
        int key = a[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

