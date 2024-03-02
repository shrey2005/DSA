/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
#include<string.h>
using namespace std;
 
void minLengthWord(char input[], char output[]){
		
	// Write your code here
	string word = "";
	int strLen[1000];
  	int count = 0;
    for(int i = 0 ; i <= strlen(input);i++){
        if(input[i] == ' ' || i == strlen(input)){
        	strLen[count] = word.length();
            count++;
          	word = "";
        }
        else{
            word+= input[i];
        }
 	 }
  
	int min = strLen[0];
	for(int i = 0; i < count ; i++){
		if(min > strLen[i]){
			min = strLen[i];
		}
	}
  
	string minLengthStr = "";
	for(int i = 0 ;  i <= strlen(input);i++){
	    if(input[i] == ' '  || i == strlen(input)){
			if(min == word.length()){
				minLengthStr = word;
				break;
			}
			word = "";
		}
		else{
		    word+= input[i];
		}
	}
	
	int i = 0;
	for( ; i < min ; i++){
		output[i] = minLengthStr[i];
	}
	
	output[i] = '\0';
}


