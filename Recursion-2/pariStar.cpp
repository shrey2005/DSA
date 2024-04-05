#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print the changed string.

void pairStar(char input[]) {
    // Write your code here
    if(input[0] == '\0'){
        return;
    }
    if(input[0] == input[1]){
        int countIndex = 0;
        while(input[countIndex] != '\0'){
            countIndex++;
        }

        while(countIndex >= 1){
            input[countIndex + 1] = input[countIndex];
            countIndex--;
        }
        input[1] = '*';
        pairStar(input+2);
    }
    pairStar(input+1);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

