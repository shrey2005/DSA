#include<iostream>
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

int main()
{
    char ch[100001];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>ch;
        func(ch);
        cout<<ch;
	cout<<endl;
    }
}