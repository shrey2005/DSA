#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	if(input.length() == 0 || input.length() == 1){
		output[0] = input;
		return 1;
	}

	string outputSize[1000];
	int smallOutput = returnPermutations(input.substr(1), outputSize);

	char firstChar = input[0];
	int k = 0;

	for(int i = 0; i < smallOutput; i++){
		for(int j = 0; j <= outputSize[i].length(); j++){
			output[k] = outputSize[i].substr(0, j) + firstChar + outputSize[i].substr(j);
			k++;
		}
	}
	return k;
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}