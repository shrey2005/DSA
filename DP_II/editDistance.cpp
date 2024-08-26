#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2) {
	// Write your code here
	if(s1.length() == 0){
		return s2.length();
	}

	if(s2.length() == 0){
		return s1.length();
	}

	if(s1[0] == s2[0]){
		return editDistance(s1.substr(1), s2.substr(1));
	}

	int insertCh = editDistance(s1.substr(1), s2) + 1;
	int deleteCh = editDistance(s1, s2.substr(1)) + 1;
	int updateCh = editDistance(s1.substr(1), s2.substr(1)) + 1;

	int ans = min(insertCh, min(deleteCh, updateCh));
	return ans;
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}