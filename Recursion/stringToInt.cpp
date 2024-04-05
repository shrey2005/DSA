#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
    cout<<"input : 0 : "<<input<<endl;
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
            cout<<"index 1 : "<<result<<endl;
            return result + stringToNumber(input+1);
        }
        else{
            cout<<"index 2 : "<<index<<endl;
            cout<<"Input 2 : "<<input<<endl;
            string str;
            for(int i = 1; i < index; i++){
                str += '0';
            }
            string newStr = input[0] + str;
            int result = stoi(newStr);
            cout<<"New Str : "<<newStr<<endl;
            cout<<"Input : ****"<<input<<endl;
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

