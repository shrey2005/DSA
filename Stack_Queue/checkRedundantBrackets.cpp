#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
	int i = 0;
	stack<char> str;
	while(expression[i] != '\0'){
		if(expression[i] != ')'){
			str.push(expression[i]);
		}
		else if(expression[i] == ')'){

			char topEle = str.top();
			str.pop();

			bool redundant = true;

			while(topEle != '('){
				if(topEle == '+' || topEle == '-' || topEle == '*' || topEle == '/'){
					redundant = false;
				}
				topEle = str.top();
				str.pop();
			}

			if(redundant){
				return true;
			}
		}
		i = i + 1; 
	}
	return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}

