#include <iostream>
#include <string>
using namespace std;

#include<stack>

bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> s;

    int i = 0;
    while(expression[i] != '\0'){
        if(expression[0] == ')'){
            return false;
        }
        if(expression[i] == '('){
            s.push(expression[i]);
        }
        else if(expression[i] == ')'){
            s.pop();
        }
        i++;
    }

    bool ans = s.empty();
    if(ans){
        return true;
    }
    return false;
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}