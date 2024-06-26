#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double geometricSum(int k) {
    // Write your code here
    if(k == 0){
        return 1;
    }
    double result = (double(1) / (pow(2,k)));
    k--;
    return result + geometricSum(k);
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}


