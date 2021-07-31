#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    // dp[i][j] はsのi番目の文字までで、tのj番目までの文字を作るときの場合の数
    // dp[n][8] を求めればよい
    vector dp(n + 1, vector<int>(9));
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
    }
    
    const int mod = 1000000007;
    string t = "chokudai";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i] != t[j]) {
                dp[i + 1][j + 1] = dp[i][j + 1];
            } else {
                dp[i + 1][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
            }
        }
    }
    return 0;
}