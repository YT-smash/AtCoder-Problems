/**
 *    author:  ytsmash
 *    created: 27.08.2021 08:54:20
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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) { cin >> A[i] >> B[i]; }

    ll ans = INF;
    // 答えが最小値になるようなスタート、ゴールの位置の候補はそれぞれA[0] ~ A[N-1], B[0] ~ B[N-1]に限られる
    for (auto v1 : A) {
        for (auto v2 : B) {
            ll dist = 0;
            for (int i = 0; i < N; i++) {
                dist += abs(v1 - A[i]);
                dist += abs(A[i] - B[i]);
                dist += abs(v2 - B[i]);
            }
            chmin(ans, dist);
        }
    }
    cout << ans << "\n";
    return 0;
}