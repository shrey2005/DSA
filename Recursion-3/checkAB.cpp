#include <iostream>
#include <cstring>

using namespace std;

bool checkPairExist(char input[], int index){    
	if(input[0] == '\0'){
        return true;
    }
    if(input[0] != 'a'){
        return false;
    }
    
    int calStringSize = strlen(input);
    if(calStringSize > 2){
        if(input[1] == 'b' && input[2] == 'b'){
            return checkPairExist(input + 3, index);
        }
    }
    return checkPairExist(input + 1, index);
}

bool checkAB(char input[]) {
	// Write your code here
	bool flagAB = false;
	if(input[0] == 'a'){
	    int index = 0;
	    flagAB = checkPairExist(input, index);
	}
    return flagAB;
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
