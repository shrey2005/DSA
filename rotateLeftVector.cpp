#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();
    d = d % n;
    vector<int> resultRotate;
    resultRotate.insert(resultRotate.end(), arr.begin() + d, arr.end());
    resultRotate.insert(resultRotate.end(), arr.begin(), arr.begin() + d);
    
    return resultRotate;
}
int main() 
{
    int n, d;
    cout<<"Enter size of array (n) : ";
    cin>>n;
    
    cout<<"Enter number of left rotations : ";
    cin>>d;
    
    vector<int> input(n);
    cout<<"Enter "<< n << " elements : ";
    for(int i = 0; i < n; i++){
      cin>>input[i];
    }
    
    vector<int> result = rotateLeft(d, input);
    for(int i = 0; i < n; i++){
      cout<<result[i]<<" ";
    }

    return 0;
}