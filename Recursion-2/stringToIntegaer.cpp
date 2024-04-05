#include<bits/stdc++.h>

using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
     if(input[0] == '\0'){
        return 0;
    }
    if(input[0] != '0'){
        int index = 0;
        while(input[index] != '\0'){
            index++;
        }
        if(index == 1){
            int result = atoi(input);
            return result + stringToNumber(input+1);
        }
        else{
            string str = "";
            for(int i = 1; i < index; i++){
                str += '0';
            }
            string newStr = input[0] + str;
            int result = stoi(newStr);
            return result + stringToNumber(input+1);
        }
    }
    return stringToNumber(input+1);
}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
