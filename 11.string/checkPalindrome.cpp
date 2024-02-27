
bool checkPalindrome(string str) {
    
    int strLen = str.size();

    bool flagPalindrome = true;

    int i = 0;
    int j = strLen - 1;

    while( i <= j){
        if(str[i] != str[j]){
            flagPalindrome = false;
        }
        i++;
        j--;
    }

    return flagPalindrome;
    
   /*char reversedStr[strLen];
    
    int count = 0;
    for(int i = strLen - 1; i >= 0 ;i--){
        reversedStr[count] = str[i];
        count++;
    }

     reversedStr[count++] = '\0';

    if(str == reversedStr){
        return true;
    }
    return false;*/
}