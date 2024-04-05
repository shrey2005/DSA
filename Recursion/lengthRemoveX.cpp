#include <iostream>

using namespace std;

void removeX(char str[], char x){
    if(str[0] == '\0'){
        return;
    }
    
    if(str[0] != x){
        removeX(str+1, x);
    }
    else{
        int i = 1;
        for(; str[i] != '\0'; i++){
            str[i-1] = str[i];
        }
        str[i-1] = str[i];
        removeX(str + 1,x);
    }
}
int len(char str[]){
    if(str[0] == '\0'){
        return 0;
    }
    return 1 + len(str + 1);
}
int main() {
    char str[100] = "xabcdxefgx";
    cout<<"Length : " <<len(str)<<endl;
    removeX(str,'x');
    cout<<"After removing : "<<str<<endl;
}