#include <iostream>
#include <vector>
using namespace std;

int lcs(string s, string t){
    if(s.length() == 0 || t.length() == 0){
        return 0;
    }
    
    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1), t.substr(1));;
    }
    else{
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
}

int lcs_memo(string s, string t, vector<vector<int>> output){
    int m = s.size();
    int n = t.size();
    if(s.length() == 0 || t.length() == 0){
        return 0;
    }
    
    if(output[m][n] != -1){
        return output[m][n];
    }
    
    int ans;
    if(s[0] == t[0]){
        ans = 1 + lcs_memo(s.substr(1), t.substr(1), output);
    }
    else{
        int a = lcs_memo(s.substr(1), t, output);
        int b = lcs_memo(s, t.substr(1), output);
        int c = lcs_memo(s.substr(1), t.substr(1), output);
        ans = max(a, max(b, c));
    }
    output[m][n] = ans;
    return ans;
}

int lcs_DP(string s, string t){
    int m = s.size();
    int n = t.size();
    
    int **output = new int*[m];
    for(int i = 0; i <= m; i++){
        output[i] = new int[n+1];
    }
    
    for(int i = 0; i <= m; i++){
        output[i][0] = 0;
    }
    
    for(int j = 0; j <= n; j++){
        output[0][j] = 0;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[m-i] == t[n-j]){
                output[i][j] = 1 + output[i-1][j-1];
            }
            else{
                int a = output[i][j-1];
                int b = output[i-1][j];
                int c = output[i-1][j-1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }
    return output[m][n];
}
int main() {
    string s, t;
    cin>>s;
    cin>>t;
    
    // int lcsResult = lcs(s, t);
    // int m = s.size();
    // int n = t.size();
    
    // vector<vector<int>> output(m + 1, vector<int>(n + 1, -1));
    // int lcsResultMemo = lcs_memo(s, t, output);
    // cout<<lcsResultMemo<<endl;
    
    cout<<lcs_DP(s, t)<<endl;
}