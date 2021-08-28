/**
 *    author:  ytsmash
 *    created: 27.08.2021 09:57:40
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
    int m;
    cin >> m;
    vector<P> p;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    int n;
    cin >> n;
    vector<P> q;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        q.push_back(make_pair(x, y));
    }
    sort(all(q));

    int ansx, ansy;
    rep(i, n) {
        int dx = q[i].first - p[0].first;
        int dy = q[i].second - p[0].second;
        bool flag = true;
        rep(j, m) {
            P next = make_pair(p[j].first + dx, p[j].second + dy);
            int ind = lower_bound(all(q), next) - q.begin();
            if (next != q[ind]) flag = false;
        }
        if (flag) {
            ansx = dx;
            ansy = dy;
        }
    }
    cout << ansx << " " << ansy << "\n";
    return 0;
}