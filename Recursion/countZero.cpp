#include <iostream>
using namespace std;

int countZeros(int n) {
    // Write your code here
    if(n <= 9){
        if(n == 0 ) return 1;
        return 0;
    }
    if(n % 10 == 0){
        return 1 + countZeros(n/10);
    }
    return countZeros(n / 10);
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}