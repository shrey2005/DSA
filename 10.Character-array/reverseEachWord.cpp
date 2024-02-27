void reverseEachWord(char input[]) {
    // Write your code here

    int from = 0;
    int to = 0;
    int length = strlen(input);
    for(int i = 0; i <= length; i++){
        if(input[i] == ' ' || i == length){
            to = i - 1;
            while(from < to){
                char temp = input[from];
                input[from] = input[to];
                input[to] = temp;
                from++;
                to--;
            }
            from = i + 1;
        }
    }
}