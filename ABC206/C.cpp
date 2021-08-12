/**
 *    author:  ytsmash
 *    created: 12.08.2021 19:34:39
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
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }
    sort(all(A));
    A.push_back(-1);
    ll cnt = 1;
    ll ans = (N * (N - 1)) / 2;
    rep(i, N) {
        if (A[i] == A[i + 1]) {
            cnt++;
        } else {
            ans -= (cnt * (cnt - 1)) / 2;
            cnt = 1;
        }
    }
    cout << ans << "\n";
    return 0;
}