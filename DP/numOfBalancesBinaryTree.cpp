#include <iostream>
#include<cmath>
using namespace std;

int balancedBSTHelper(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    int modResult = (int) (pow(10, 9)) + 7;
    int sumBSTX = balancedBSTHelper(n - 1);
    int sumBSTY =  balancedBSTHelper(n - 2);
    int first =  (int)(((long)(sumBSTX) * sumBSTX) % modResult);
    int second = (int)((2 * (long)(sumBSTX) * sumBSTY) % modResult);
    int third = (int) (first + second) % modResult;
    return third;
}

int balancedBTs(int n) {
    // Write your code here
   int result = balancedBSTHelper(n);
   return result;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}