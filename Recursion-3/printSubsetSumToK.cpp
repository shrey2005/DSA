#include <iostream>
#include<vector>
using namespace std;

void printSubset(vector<int> &subset){
    for(int num : subset){
        cout<<num<<" ";
    }
    cout<<endl;
}
void subSetSumToK(int input[], int n, int k, vector<int> &res){
    if(k == 0){
        printSubset(res);
        return;
    }

    if(n == 0){;
        return;
    }

    res.push_back(input[0]);
    subSetSumToK(input + 1,  n - 1, k - input[0], res);

    res.pop_back();
    subSetSumToK(input + 1, n - 1, k,res);

}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int> res;
    subSetSumToK(input, size, k, res);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}

