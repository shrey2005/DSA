#include <iostream>
#include <algorithm>
using namespace std;

string reverseStringWordWise(string input)
{
    //Write your code here
 string result = "";
  string words = "";
  
  bool isFoundStr = false;
  int startIndex = 0, endIndex = 0;
  for(int i = 0 ; i <= input.length(); i++){
      isFoundStr = false;
      if(input[i] == ' ' ||  i == input.length()){
          isFoundStr = true;
          endIndex = i - 1;
          words = input.substr(startIndex, (endIndex - startIndex)+1);
          words += " ";
          startIndex = i + 1;
      }
      if(isFoundStr){
          result.insert(0,words);
          words = "";
      }
  }
  return result;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}