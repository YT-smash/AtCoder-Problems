/**
 *    author:  ytsmash
 *    created: 25.08.2021 18:44:28
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
    ll N, M;
    cin >> N >> M;
    const ll MOD = 1000000007;

    vector<vector<int>> G(N + 10);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(N + 10, -1);
    vector<ll> cnt(N + 10);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    cnt[0] = 1;

    while (!que.empty()) {
        int crr = que.front();
        que.pop();
        for (auto nxt : G[crr]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[crr] + 1;
                cnt[nxt] = cnt[crr];
                que.push(nxt);
            } else if (dist[nxt] == dist[crr] + 1) {
                cnt[nxt] += cnt[crr];
                cnt[nxt] %= MOD;
            }
        }
    }
    cout << cnt[N - 1] << "\n";
    return 0;
}