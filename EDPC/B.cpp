#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int K;
    cin >> N >> K;
    vector<int> h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = dp[0] + abs(h[0] - h[1]);

    for(int i = 2; i < N; i++) {
        dp[i] = dp[i - 1] + abs(h[i - 1] - h[i]);
        for(int j = 2; j < K + 1; j++) {
            if(i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i - j] - h[i]));
            }
        }
    }

    cout << dp[N - 1] << endl;
    return 0;
}