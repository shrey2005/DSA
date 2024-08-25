#include <iostream>
#include <string.h>

using namespace std;

void printCode(string input, string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }

    int num1 = input[0] - '0';
    if(num1 >= 1 && num1 <= 9){
        char ch1 = 'a' + num1 - 1;
        printCode(input.substr(1), output+ch1);
    }

    if(input.length() > 1){
        int num2 = (input[0] - '0') * 10 + (input[1] - '0');
        if(num2 >= 10 && num2 <= 26){
            char ch2 = 'a' + num2 - 1;
            printCode(input.substr(2), output+ch2);
        }

    }
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output = "";
    printCode(input, output);
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
