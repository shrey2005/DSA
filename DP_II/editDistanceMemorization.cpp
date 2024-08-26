#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

int editDistanceHelper(string s1, string s2, int **output){
	int m = s1.size();
	int n = s2.size();
	if(s1.size() == 0 || s2.size() == 0){
		return max(s1.size(), s2.size());
	}
	
	if(output[m][n] != -1){
		return output[m][n];
	}

	int ans;
    if(s1[0] == s2[0]){
        ans = editDistanceHelper(s1.substr(1), s2.substr(1), output);
    }
    else{
        int a = editDistanceHelper(s1.substr(1), s2, output) + 1;
        int b = editDistanceHelper(s1, s2.substr(1), output) + 1;
        int c = editDistanceHelper(s1.substr(1), s2.substr(1), output) + 1;
        ans = min(a, min(b, c));
    }
    output[m][n] = ans;
    return ans;
}

int editDistanceHelperDP(string s1, string s2){
	int m = s1.size();
	int n = s2.size();
    
    int **output = new int*[m+1];
    for(int i = 0; i <= m; i++){
        output[i] = new int[n+1];
    }
    
	for(int j = 0; j <= n; j++){
        output[0][j] = j;
    }

    for(int i = 0; i <= m; i++){
        output[i][0] = i;
    }

	for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[m-i] == s2[n-j]){
                output[i][j] = output[i-1][j-1];
            }
            else{
                int a = output[i][j-1];
                int b = output[i-1][j];
                int c = output[i-1][j-1];
                output[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }

    return output[m][n];
}
int editDistance(string s1, string s2)
{
	//Write your code here
	// int m = s1.size();
	// int n = s2.size();

	// int **output = new int*[m+1];
	// for(int i = 0; i <= m; i++){
	// 	output[i] = new int[n+1];
	// 	for(int j = 0; j<= n; j++){
	// 		output[i][j] = -1;
	// 	}
	// }
	// vector<vector<int>> output(m + 1, vector<int>(n + 1, -1));

	// int result = editDistanceHelper(s1, s2, output);
	// return result;

	int result2 = editDistanceHelperDP(s1, s2);
	return result2;
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}