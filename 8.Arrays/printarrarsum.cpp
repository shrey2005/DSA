#include<iostream>
using namespace std;

int main(){
    /* Read input as specified in the question.
     * Print output as specified in the question.
     */

    int n;
    cin>>n;

    int elements[100000];
    int sum = 0;

    for(int i = 0; i < n ; i++){
        cin>>elements[i];
        sum+=elements[i];
    }

    cout<<sum<<endl;
    
}


