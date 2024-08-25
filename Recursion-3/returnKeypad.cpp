#include <iostream>
#include <string>
using namespace std;

string getString(int d){
    if(d == 2){
        return "abc";
    }
    if(d == 3){
        return "def";
    }
    if(d == 4){
        return "ghi";
    }
    if(d == 5){
        return "jkl";
    }
    if(d == 6){
        return "mno";
    }
    if(d == 7){
        return "pqrs";
    }
    if(d == 8){
        return "tuv";
    }
    if(d == 9){
        return "wxyz";
    }
    return " ";
}
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
   if(num == 0){
        output[0] = "";
        return 1;
    }

    int lastDigit = num % 10;
    int smallNumber = num / 10;
    int smallOutputResult = keypad(smallNumber, output);
    string options = getString(lastDigit);
    
    for(int i = 0; i < options.length() - 1; i++){
       for(int j = 0; j < smallOutputResult; j++){
           output[j + (i + 1) * smallOutputResult] = output[j];
       }
    }
    
    int k = 0;
    for(int i = 0; i < options.length(); i++){
        for(int j = 0; j < smallOutputResult; j++){
            output[k] = output[k] + options[i];
            k++;
        }
    }
    return options.length() * smallOutputResult;
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
