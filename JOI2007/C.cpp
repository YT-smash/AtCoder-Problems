/**
 *    author:  ytsmash
 *    created: 27.08.2021 07:31:23
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
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i, n) { cin >> p[i].first >> p[i].second; }
    sort(all(p));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dx = p[i].first - p[j].first;
            int dy = p[i].second - p[j].second;
            int area = dx * dx + dy * dy;
            P q(p[i].first - dy, p[i].second + dx),
                q2(p[j].first - dy, p[j].second + dx);
            int ind1 = lower_bound(all(p), q) - p.begin();
            int ind2 = lower_bound(all(p), q2) - p.begin();

            if (q == p[ind1] && q2 == p[ind2]) {
                chmax(ans, area);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}