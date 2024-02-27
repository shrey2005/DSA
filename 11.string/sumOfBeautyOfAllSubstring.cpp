int sumOfBeauty(string s) {
	// Write your code here.
    int sum=0;
    
	for(int i = 0; i < s.length();i++){
        string word = "";
        for(int j = i ; j < s.length(); j++){
            word+=s[j];
            int asciiTable[26]={0};
          
            for(int k = 0; word[k] != '\0'; k++){
                int index = word[k]-'a';
                asciiTable[index] = asciiTable[index] + 1;
            }
            int min = INT_MAX;
            int max = INT_MIN;
            for(int k = 0; k<26; k++){
                if(asciiTable[k] >max){
                    max = asciiTable[k];
                }
                if(asciiTable[k] < min && asciiTable[k] != 0){
                    min= asciiTable[k];
                }
            }
            sum+=(max-min);
        }
    }
    return sum;
}
