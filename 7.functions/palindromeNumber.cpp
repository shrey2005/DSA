bool palindrome(int n)
{
    // Write your code here
    int num = n;
    int copyNum = n;
    int remainder = 0, palindrome = 0;
    while(num != 0){
        remainder = n % 10;
        palindrome = (palindrome * 10) + remainder;
        n = n / 10;
        num = n;
    }

    if(copyNum == palindrome){
        return true;
    }
    return false;
}