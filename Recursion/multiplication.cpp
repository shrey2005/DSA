#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    // Write your code here
    if(n == 0){
        return 0;
    }
    n--;
    int res = m + multiplyNumbers(m,n);
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
