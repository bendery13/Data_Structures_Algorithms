#include <iostream>
#include <chrono>
using namespace std;

void tower(int n, char source, char target, char auxiliary, long long int &moveCount);

int main() {
    long long int moveCount = 0;
    int n;  
 

    for (n = 3; n <= 35; n++){
        auto start = chrono :: high_resolution_clock :: now();
        tower(n, 'S', 'T', 'A', moveCount);
        auto stop = chrono :: high_resolution_clock :: now();
        
        chrono::duration<double> timeTaken = stop - start;

        cout << "N = " << n << "\n";
        cout << "Total number of moves: " << moveCount << "\n";
        cout <<  timeTaken.count() * 1000 << " miliseconds.\n\n";
        moveCount = 0;
    }
    return 0;
}

void tower(int n, char source, char target, char auxiliary, long long int &moveCount) {
    if (n == 1) {
        ++moveCount;
        return;
    }
    else{
        tower(n - 1, source, auxiliary, target, moveCount);
        ++moveCount;
        tower(n - 1, auxiliary, target, source, moveCount);
        return;
    }
}
