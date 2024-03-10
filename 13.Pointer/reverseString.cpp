#include<string.h>
using namespace std;
void func(char *str) 
{
    //write your code here
    int totalLen = strlen(str) - 1;
    for(int i = 0; i < totalLen;i++){
        char temp = *(str+i);
        *(str+i) = *(str+totalLen);
        *(str+totalLen) = temp;
        totalLen--;
    }
}
