string getCompressedString(string &input) {
    // Write your code here.
    string result = "";
    
    int left = 0, right = 0;
    
    while(left < input.size()){
        while(right < input.size() && input[left] == input[right]){
            right++;
        }
        result += input[left];
        int count = right - left;
        if(count > 1){
            result+= to_string(count);
        }
        left = right;
    }
    return result;
}