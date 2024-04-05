#include <utility>
#include <algorithm>
#include <climits>
#include <iostream>
#include<vector>

using namespace std;

int sumOfMaxMin(vector<int> arr, int n){
	int min = arr[0];
    int max = arr[0];
    for(int i = 0; i < n ; i++){
        if(min < arr[i]){
            min = arr[i];
        }
        if(max > arr[i]){
            max = arr[i];
        }
    }

    return min + max;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testcase;
    cin>>testcase;
    
    while(testcase--){

        int n;
        cin>>n;

        vector<int>arr(n);
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int ans = sumOfMaxMin(arr, n);

        cout<<ans<<endl;
    }
    return 0;
}