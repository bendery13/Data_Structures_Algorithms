#include <iostream>
#include <chrono>
using namespace std;

long long int RM4(int n);
long long int RM6(int n);
int main(){
    long long int result = 0;
    int n;
    cout << "Using RM4:" << endl;
    for (n = 3; n <= 35; n++){
        auto start = chrono :: high_resolution_clock :: now();
        result = RM4(n);
        auto stop = chrono :: high_resolution_clock :: now();
        chrono::duration<double> timeTaken = stop - start;
        
        cout << "N = " << n << endl;
        cout << "result = " << result << endl;
        cout <<  timeTaken.count() * 1000000000 << " nanoseconds.\n\n";
    }
    cout << "Using RM6:" << endl;
    for (n = 3; n <= 35; n++){
        auto start = chrono :: high_resolution_clock :: now();
        result = RM6(n);
        auto stop = chrono :: high_resolution_clock :: now();
        chrono::duration<double> timeTaken = stop - start;
        
        cout << "N = " << n << endl;
        cout << "result = " << result << endl;
        cout <<  timeTaken.count() * 1000000000 << " nanoseconds.\n\n";
    }


    return 0;
}
long long int RM4(int n){
    if (n == 0){
        return 1;
    }
    else{
        return 3 * RM4(n - 1);
    }
}

long long int RM6(int n){
    if (n == 0){
        return 1;
    }
    else if(n % 2 == 0){
        return (RM6(n/2) * RM6(n/2));
    }
    else{
        return (3*(RM6(n/2) * RM6(n/2)));
    }

}