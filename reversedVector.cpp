#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> reverseArray(vector<int> a){
    reverse(a.begin(),a.end());
    return a;
}
int main() 
{
    vector<int> myArray = {1, 2, 3, 4, 5};

    vector<int> result = reverseArray(myArray);

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}