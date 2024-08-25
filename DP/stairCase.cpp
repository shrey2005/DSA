#include<bits/stdc++.h>
#include<cmath>
#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main()
{
    // take input from the user.
    int n, t;
    cin>>t;

    long *result = new long[t];
    for(int i = 0; i < t; i++){
        cin>>n;

        if( n == 0){
            result[i] = 1;
        }
        else if(n == 1){
            result[i] = 1;
        }
        else if(n == 2){
            result[i] = 2;
        }
        else{
            long a = 1, b = 1, c = 2, d;
            for (int j = 3; j <= n; j++) {
                d = (a + b + c) % MOD ;
                a = b;
                b = c;
                c = d;
            }
            result[i] = c;
        }
    }
    
    for(int i = 0; i < t ; i++){
        cout<<result[i]<<endl;
    }
}