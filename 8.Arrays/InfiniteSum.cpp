vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here

    vector<int> result;
    
    for(auto row : queries){
        int sum = 0;
        long long L = row[0];
        long long R = row[1];
        for(long long k = L ; k <= R; k++){
            int calculate = (k - 1) % n;
            sum = sum + arr[calculate];
        }
        result.push_back(sum);
    }
    return result;
}

int main() {
	// your code goes here
	vector<int> ele = {5,2,6,9};
	int n = ele.size();
	vector<vector<long long>> multi = {{1L, 5L}, {10L, 13L},{7L, 11L}};
	int q = 3;
	vector<int> result = sumInRanges(ele,n,multi, q);
	for(int i = 0; i < result.size();i++){
	    cout<<result[i]<<" ";
	}
    return 0;
}