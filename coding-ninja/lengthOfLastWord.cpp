
#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
    int lengthLastWord = 0;
    int i = s.length() - 1;

    while(i >= 0 && s[i] == ' '){
        i--;
    }

    while(i >= 0 && ((s[i] >= 'a' && s[i] <= 'z') || s[i] >='A' && s[i] <= 'Z')){
        lengthLastWord++;
        i--;
    }
    return lengthLastWord;
}

int main() {
    string myStr = "a ";
    int result = lengthOfLastWord(myStr);

    cout<<result;
}