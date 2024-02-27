int makeBeautiful(string str) {
	// Write your code here
	int count1 = 0, count2 = 0;
  for(int i = 0 ; i < str.length();i++){
      char intValue = str[i];
      int convertedInt = intValue;
      if(i % 2 == 0){
          if(str[i] != 48){
              count1++;
          }
      }
      if(i % 2 == 1){
          if(str[i] != 49){
              count1++;
          }
      }
  }
  
  for(int i = 0 ; i < str.length();i++){
      char intValue = str[i];
      int convertedInt = intValue;
      if(i % 2 == 0){
          if(str[i] != 49){
              count2++;
          }
      }
      if(i % 2 == 1){
          if(str[i] != 48){
              count2++;
          }
      }
  }
  int min = 0;
 if(count1 >= count2){
     min = count2;
 }else{
     min = count1;
 }
 return min;
}