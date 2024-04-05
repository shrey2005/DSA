#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  if(size == 0 ){
      return -1;
  }
  int n = size - 1;
  int smallAns  = lastIndex(input+1, n, x);
  if(smallAns != -1){
    return smallAns + 1;
  }
  else if(input[0] == x){
    return 0;
  }
  else{
    return -1;
  }
  return smallAns;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}


