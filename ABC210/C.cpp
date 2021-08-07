#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
template <class T> inline T chmax(T &a, const T b) {
    return a = (a < b) ? b : a;
}
template <class T> inline T chmin(T &a, const T b) {
    return a = (a > b) ? b : a;
}
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> c(N);
    rep(i, N) { cin >> c[i]; }

    map<int, int> mp;
    rep(i, K) { mp[c[i]]++; }
    int ans = mp.size();

    for(int i = K; i < N; i++) {
        mp[c[i]]++;
        mp[c[i - K]]--;
        if(mp[c[i - K]] == 0) {
            mp.erase(c[i - K]);
        }
        ans = max(ans, (int)mp.size());
    }
    cout << ans << endl;
    return 0;
}