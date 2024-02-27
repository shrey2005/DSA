void printTable(int start, int end, int step) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */

    int itr = start;
    int celsius = 0;
    while(itr <= end){
        celsius = (5  * (itr - 32))/9;
        cout<<itr<<" "<<celsius<<endl;
        itr+=step;
    }
}