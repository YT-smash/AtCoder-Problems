/**
 *    author:  ytsmash
 *    created: 13.08.2021 09:30:52
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;
    int ans = 0;
    rep(i, N) {
        rep(j, K) { ans += 100 * (i + 1) + j + 1; }
    }
    cout << ans << "\n";
    return 0;
}