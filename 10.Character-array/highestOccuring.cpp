char highestOccurringChar(char input[]) {
    // Write your code here

    int traversArr[26] = {0};
    for(int i = 0; input[i] != '\0';i++){
        int calIndex = input[i] - 97;
        traversArr[calIndex] = traversArr[calIndex] + 1;
    }
    
    int max = traversArr[0];
    int index = 0;
    for(int i = 0; i < 26; i++){
        if(traversArr[i] > max){
            max = traversArr[i];
            index = i;
        }
    }
    
    char highestChar = index + 97;
    return highestChar;
}