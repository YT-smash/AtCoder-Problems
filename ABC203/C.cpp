/**
 *    author:  ytsmash
 *    created: 13.08.2021 09:35:25
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int N;
    ll K;
    ll x, y;
    vector<pair<ll, ll>> a;
    cin >> N >> K;

    rep(i, N) {
        cin >> x >> y;
        a.push_back({x, y});
    }

    sort(all(a));
    rep(i, N) {
        if (a[i].first > K) break;
        K += a[i].second;
    }
    cout << K << "\n";
    return 0;
}