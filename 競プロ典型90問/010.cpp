/**
 *    author:  ytsmash
 *    created: 13.08.2021 15:55:41
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
    ll N;
    cin >> N;
    vector<ll> C(N), P(N);
    rep(i, N) { cin >> C[i] >> P[i]; }
    ll Q;
    cin >> Q;
    vector<ll> L(Q), R(Q);
    rep(i, Q) { cin >> L[i] >> R[i]; }

    vector<ll> sum1(N + 1, 0), sum2(N + 1, 0);
    rep(i, N) {
        sum1[i + 1] = sum1[i];
        sum2[i + 1] = sum2[i];
        if (C[i] == 1) {
            sum1[i + 1] += P[i];
        } else {
            sum2[i + 1] += P[i];
        }
    }

    rep(i, Q) {
        ll ans1 = sum1[R[i]] - sum1[L[i] - 1];
        ll ans2 = sum2[R[i]] - sum2[L[i] - 1];
        cout << ans1 << " " << ans2 << "\n";
    }

    return 0;
}