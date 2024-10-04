#include <iostream>
#include <chrono>
#include "EnhancingQuickSort.h"
using namespace std;

int main(){
    int* unsorted1 = new int[100000];
    int* unsorted2 = new int[200000];
    int* unsorted3 = new int[300000];
    int* unsorted4 = new int[400000];
    int* unsorted5 = new int[500000];

    int* sorted1 = new int[100000];
    int* sorted2 = new int[200000];
    int* sorted3 = new int[300000];
    int* sorted4 = new int[400000];
    int* sorted5 = new int[500000];
    populateSorted(sorted1, sorted2, sorted3, sorted4, sorted5);

    /*
    
    
        End Index
    
    
    */

    // This rounds of sorting uses the last index as a pivot
    populateRandoms(unsorted1, unsorted2, unsorted3, unsorted4, unsorted5);

    cout << "\n\n\n\n Back Pivot"<< endl; 
    cout <<  endl << "Unsorted Array 1:" << endl;
    auto start = chrono :: high_resolution_clock :: now();
    quickSort(unsorted1, 0, 100000 - 1);
    auto stop = chrono :: high_resolution_clock :: now();
    chrono::duration<double> timeTaken = stop - start;
    sampleArray(unsorted1);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Unsorted Array 2:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(unsorted2, 0, 200000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted2);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl <<"Unsorted Array 3:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(unsorted3, 0, 300000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted3);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Unsorted Array 4:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(unsorted4, 0, 400000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted4);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout <<  endl << "Unsorted Array 5:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(unsorted5, 0, 500000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted5);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;
    
    cout << "Sorted Arrays: " << endl;

    cout <<  endl << "Sorted Array 1:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(sorted1, 0, 100000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Sorted Array 2:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(sorted2, 0, 200000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl <<"Sorted Array 3:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(sorted3, 0, 300000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Sorted Array 4:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(sorted4, 0, 400000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout <<  endl << "Sorted Array 5:" << endl;
    start = chrono :: high_resolution_clock :: now();
    quickSort(sorted5, 0, 500000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;
    

    /*
    
    
        Middle Index
    
    
    */



    // This round of sorts uses the middle as a pivot
    cout << "\n\n\n\n Middle Pivot"<< endl; 
    populateRandoms(unsorted1, unsorted2, unsorted3, unsorted4, unsorted5);

    cout <<  endl << " Unsorted Array 1:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(unsorted1, 0, 100000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted1);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Unsorted Array 2:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(unsorted2, 0, 200000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted2);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl <<"Unsorted Array 3:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(unsorted3, 0, 300000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted3);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Unsorted Array 4:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(unsorted4, 0, 400000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted4);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout <<  endl << "Unsorted Array 5:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(unsorted5, 0, 500000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted5);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;

    cout << "Sorted Arrays: " << endl;    

    cout <<  endl << "Sorted Array 1:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(sorted1, 0, 100000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted1);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Sorted Array 2:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(sorted2, 0, 200000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted2);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl <<"Sorted Array 3:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(sorted3, 0, 300000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted3);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Sorted Array 4:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(sorted4, 0, 400000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted4);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout <<  endl << "Sorted Array 5:" << endl;
    start = chrono :: high_resolution_clock :: now();
    middleQuickSort(sorted5, 0, 500000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted5);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;



    /*
    
    
        Random Index
    
    
    */





    //This round of sorts uses a random index as a pivot
    cout << "\n\n\n\n Random Pivot"<< endl; 
    populateRandoms(unsorted1, unsorted2, unsorted3, unsorted4, unsorted5);

    cout <<  endl << "Unsorted Array 1:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(unsorted1, 0, 100000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted1);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Unsorted Array 2:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(unsorted2, 0, 200000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted2);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl <<"Unsorted Array 3:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(unsorted3, 0, 300000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted3);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Unsorted Array 4:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(unsorted4, 0, 400000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted4);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout <<  endl << "Unsorted Array 5:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(unsorted5, 0, 500000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(unsorted5);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << "Sorted Arrays: " << endl;

    cout <<  endl << "Sorted Array 1:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(sorted1, 0, 100000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted1);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Sorted Array 2:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(sorted2, 0, 200000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted2);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl <<"Sorted Array 3:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(sorted3, 0, 300000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted3);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout << endl << "Sorted Array 4:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(sorted4, 0, 400000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted4);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;


    cout <<  endl << "Sorted Array 5:" << endl;
    start = chrono :: high_resolution_clock :: now();
    randomQuickSort(sorted5, 0, 500000 - 1);
    stop = chrono :: high_resolution_clock :: now();
    timeTaken = stop - start;
    sampleArray(sorted5);
    cout << "Time taken: " << timeTaken.count() * 1000  << " milliseconds" << endl;
    

    // Clean up dynamic memory
    delete[] unsorted1;
    delete[] unsorted2;
    delete[] unsorted3;
    delete[] unsorted4;
    delete[] unsorted5;

    delete[] sorted1;
    delete[] sorted2;
    delete[] sorted3;
    delete[] sorted4;
    delete[] sorted5;

    return 0;
}
