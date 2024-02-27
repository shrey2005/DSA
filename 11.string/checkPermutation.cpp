#include <bits/stdc++.h> 
#include <string>
bool areAnagram(string &str1, string &str2){
    // Write your code here.

   for(int i = 0 ; str1[i] != '\0'; i++){
       int index = str2.find(str1[i]);
       if(index < 0){
          return false;
       }
   }
   return true;
}