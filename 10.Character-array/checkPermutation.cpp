bool isPermutation(char input1[], char input2[]) {
    // Write your code here

    int traversArr[26] = {0};
    int count = 0;
    for(int i = 0; input1[i] != '\0';i++){
        int calIndex = input1[i] - 97;
        int temp = traversArr[calIndex] + 1;
        traversArr[calIndex] = temp;
    }
    
    for(int i = 0; input2[i] != '\0';i++){
        int calIndex = input2[i] - 97;
        int temp = traversArr[calIndex] - 1;
        traversArr[calIndex] = temp;
    }
    
    for(int i = 0 ; i<26;i++){
       if(traversArr[i] != 0){
           return false;
       }
    }

    return true;
}