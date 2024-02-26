int findDigits(int n){
   int num = n;
   int countDigits = 0;
    
    while(num != 0){
        n = n / 10;
        num = n;
        countDigits++;
    }
	return countDigits;
}

bool checkArmstrong(int n){
	//Write your code here
	int numCpy = n;
    int num = n;

    int countDigits = findDigits(n); 
    
    int remainder = 0, armStrong = 0;
    while(num != 0){
        remainder = n % 10;
        armStrong +=  pow(remainder,countDigits);
        n = n / 10;
        num = n;
    }
    
    if(numCpy == armStrong){
       return true;
    }
    return false;
}
