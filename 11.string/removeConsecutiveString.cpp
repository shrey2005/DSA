string removeConsecutiveDuplicates(string str) 
{
    //Write your code here
    string newStr = "";
    int count = 1;
 
    newStr.push_back(str.at(0));
    for(int i = 1; str[i] != '\0';i++){
        if(str[i] != str[i-1]){
            newStr += str[i];
        }
    }
    return newStr;
}