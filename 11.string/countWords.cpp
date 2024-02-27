int countWords(string str) {
	// Write your code here
	int count = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == ' '){
			count++;
		}
	}

	return count+1;
}