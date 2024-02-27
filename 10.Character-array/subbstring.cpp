void printSubstrings(char input[]) {
    // Write your code here
    bool printSub = false;
    for(int k = 0; k < strlen(input); k++){
        for(int i = 0; i < strlen(input); i++){
            printSub = false;
            for(int j = k; j <= i ;j++){
                cout<<input[j];
                printSub = true;
            }
           if(printSub){
             cout<<endl;
           }
        }
    }
}