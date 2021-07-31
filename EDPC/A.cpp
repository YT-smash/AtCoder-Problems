#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }

    // dp[i]は 足場i+1に辿り着くまでに支払うコストの総和の最小値
    vector<int> dp(N + 1);
    dp[0] = 0;                // 最初足場1にカエルがいる
    dp[1] = abs(h[0] - h[1]); // 足場2へは足場1から行く方法のみ

    // iが２以上の場合
    for(int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]),
                    dp[i - 2] + abs(h[i - 2] - h[i]));
    }
    cout << dp[N - 1] << endl;
    return 0;
}