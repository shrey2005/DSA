#include <iostream>
#include <string.h>
using namespace std;


int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.empty()){
        output[0] = "";
        return 1;
    }

    int num1 = input[0] - '0';
    int smallOutputSize1 = 0;
    if(num1 >= 1 && num1 <= 9){
        char ch1 = 'a' + num1 - 1;
        string tempOutput[10000];
        smallOutputSize1 = getCodes(input.substr(1), tempOutput);
        for(int i = 0; i < smallOutputSize1; i++){
            output[i] = ch1 + tempOutput[i];
        }
    }

    int smallOutputSize2 = 0;
    if(input.length() > 1){
        int num2 = (input[0] - '0') * 10 + (input[1] -'0');
        if(num2 >= 10 && num2 <= 26){
            char ch2 = 'a' + num2 - 1;
            string tempOutput[10000];
            smallOutputSize2 = getCodes(input.substr(2), tempOutput);
            for(int i = 0; i < smallOutputSize2; i++){
                output[smallOutputSize1 + i] = ch2 + tempOutput[i];
            }
        }
    }

    return smallOutputSize1 + smallOutputSize2;
}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
