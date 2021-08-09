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
    int N;
    cin >> N;
    vector<int> t(N);
    vector<int> l(N);
    vector<int> r(N);
    rep(i, N) { cin >> t[i] >> l[i] >> r[i]; }

    int ans = 0;

    

    cout << ans << endl;
    return 0;
}