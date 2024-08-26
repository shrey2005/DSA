#include <iostream>
#include <string>

#include<vector>
#include<climits>
using namespace std;
int getAns(char *s1, char *s2, int len1, int len2, int **dp){
    if(len1 <= 0){
        return 1001;
    }

    if(len2 <= 0){
        return 1;
    }

    if(dp[len1][len2] > -1){
        return dp[len1][len2];
    }

    int ans = 0;
    int option1 = getAns(s1 + 1, s2, len1 - 1, len2, dp);
    int i = 0;
    for(; i < len2; i++){
        if(s1[0] ==s2[i]){
            break;
        }
    }

    if(i == len2){
        return 1;
    }

    int option2 = 1 + getAns(s1 + 1, s2 + i + 1, len1 -1, len2 - 1 - i, dp);
    int result = min(option1, option2);
    dp[len1][len2] = result;
    return result;
}
int solve(string s, string v) {
    // Write your code here

    char *s1 = new char[s.length()];
    char *s2 = new char[v.length()];

    for(int i = 0 ; i < s.length(); i++){
        s1[i] = s[i];
    }

    for(int i = 0; i < v.length(); i++){
        s2[i] = v[i];
    }

    int **dp = new int*[s.length() + 1];
    for(int i = 0; i <= s.length() ;i++){
        dp[i] = new int[v.length() + 1];
        for(int j = 0; j <= v.length(); j++){
            dp[i][j] = -1;
        }
    }

    return getAns(s1, s2, s.length(), v.length(), dp);
}

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}