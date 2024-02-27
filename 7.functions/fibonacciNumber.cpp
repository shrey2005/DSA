
bool checkMember(int n){

  /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Return output and don't print it.
   * Taking input and printing output is handled automatically.
  */

    int a = 0, b = 1, c = 0 ;
    
    int i = 0;
    while(i <= n){
        if(c == n){
            return true;
        }
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    
    return false;
}