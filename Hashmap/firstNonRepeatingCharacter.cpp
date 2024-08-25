#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h> 
#include <unordered_map>

using namespace std;

char firstNonRepeatingCharacter(string str) {

  // Write your code here
  unordered_map<char, int> unqiue;
  for(int i = 0; str[i] != '\0';i++){
    unqiue[str[i]]++;
  }

  char minChar = str[0];
  for(int i = 0; str[i] != '\0';i++){
    if(unqiue[str[i]] == 1){
      minChar = str[i];
      break;
    }
  }
  return minChar;
}

class Runner
{
    int t;

    
    vector<string> arr;


public:
    void takeInput()
    {

 cin >> t;
        arr.resize(t);
        

        for (int tc = 0; tc < t; tc++)
        {
       cin>>arr[tc];

        }

        
    }

    void execute()
    {
         vector<string> arrCopy = arr;
        for (int i=0;i<t;i++){
            firstNonRepeatingCharacter(arrCopy[i]);
        }
    }


    void executeAndPrintOutput()
    {
        for (int tt=0;tt<t;tt++){
            char v=firstNonRepeatingCharacter(arr[tt]);
            {
              cout<<v;         
            }
            cout<<"\n";
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
