/**
 *    author:  ytsmash
 *    created: 20.08.2021 20:24:19
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> t(N);
    rep(i, N) { cin >> t[i]; }

    
    int ans = 10000;
    for (int bit = 0; bit < (1 << N); bit++) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                sum1 += t[i];
            } else {
                sum2 += t[i];
            }
        }
        int sum = max(sum1, sum2);
        ans = min(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}