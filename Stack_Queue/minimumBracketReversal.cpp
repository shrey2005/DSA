#include <iostream>
#include <string>
#include <stack>
using namespace std;
int countBracketReversals(string input) {
	// Write your code here
	int i = 0;
	stack<char> s;
	while(input[i] != '\0'){
	    i++;
	}

	if(i % 2 != 0){
	    return -1;
	}

	int j = 0;
	int count = 0;
	while(input[j] != '\0'){
		if(input[j] == '{'){
			s.push(input[j]);
		}
		else if(input[j] == '}'){
            if (!s.empty() && s.top() == '{') {
                s.pop();
                
            } else if (!s.empty() && s.top() == '}') {
				s.push(input[j]);
            } else if(s.empty()){
                s.push(input[j]);
            }
        }
		j++;
	}
	while(!s.empty()){
        char charFirst = s.top();
        s.pop();
        char charSecond = s.top();
        s.pop();
        if(charFirst != charSecond){
            count = count + 2;
        }
        else{
            count = count + 1;
        }
    }
	return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}