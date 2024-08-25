#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str) {
	// Write your code here
	unordered_map<char, bool> unique;
	string newStr = "";
	for(int i = 0; str[i] != '\0'; i++){
		if(unique.count(str[i]) > 0){
			continue;
		}
		unique[str[i]] = true;
		newStr += str[i];
	}
	return newStr;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}