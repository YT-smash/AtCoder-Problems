/**
 *    author:  ytsmash
 *    created: 16.08.2021 18:28:32
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
    string S;
    cin >> S;

    int n = S.length();
    ll ans = 0;
    rep(i, 1 << n - 1) {
        ll sum = 0;
        ll a = S[0] - '0';
        rep(j, n - 1) {
            if (i & (1 << j)) {
                sum += a;
                a = 0;
            }
            a = 10 * a + S[j + 1] - '0';
        }
        sum += a;
        ans += sum;
    }
    cout << ans << "\n";
}