void swapChar(char mystr[],int index){
    for(int i = index; mystr[i] != '\0'; i++){
        mystr[i] = mystr[i+1];
    }
}
void trimSpaces(char input[]) {
    // Write your code here
    int totalLen = 0;
    for(int j = 0; input[j] != '\0'; j++){
      if(input[j] != '\0'){
          totalLen++;
      }
   }
    int count = totalLen;
    for(int i = 0; input[i] != '\0';i++){
      bool spaceFound = false;
      if(input[i] == ' '){
          spaceFound = true;
      }
      if(spaceFound){
         input[count] = '\0'; 
         count = totalLen;
         swapChar(input, i);
         i--;
      }
  }
}