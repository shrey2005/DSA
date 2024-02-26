int factoria(int n){
    int fact = 1;
    for(int i = 1; i<= n; i++){
        fact *= i;
    }
    return fact;
}

int permutation(int n, int r) {
    //Write your code here

    if( n<r || n < 0 || r < 0){
        cout<<"please enter n >= r >= 0";
        return 0;
    }

    int calFactn = factoria(n);
    int calFactnr = factoria( n - r);

    int npr = calFactn / calFactnr;
    
    return npr;
    
}
