#include <iostream>
#include<cmath>
using namespace std;

int balancedBTs(int n) {
    // Write your code here
    int *ans = new int[n+1];

    ans[0] = 1;
    ans[1] = 1;

    int modResult = (int)(pow(10, 9)) + 7;
    for(int i = 2; i <= n; i++){
        int x = ans[i-1];
        int y = ans[i-2];
        int first =  (int)(((long)(x) * x) % modResult);
        int second = (int)((2 * (long)(x) * y) % modResult);
        int third = (int) (first + second) % modResult;
        ans[i] = third;
    }

    return ans[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}