/**
 *    author:  ytsmash
 *    created: 26.08.2021 20:39:08
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = 100000 * 5000 * 2;
    int c_num = 0;
    while (X >= 0 || Y >= 0) {
        ll sum = 0;
        sum += C * c_num;
        sum += max(X, 0) * A + max(Y, 0) * B;
        ans = min(ans, sum);
        c_num += 2;
        X--;
        Y--;
    }
    cout << ans << "\n";

    return 0;
}