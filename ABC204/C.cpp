/**
 *    author:  ytsmash
 *    created: 12.08.2021 20:24:20
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

const int MAX_N = 2000;
vector<vector<int>> G;
vector<bool> temp(MAX_N, false);

void dfs(int v) {
    if (temp[v]) {
        return;
    } else {
        temp[v] = true;
        for (auto vv : G[v]) {
            dfs(vv);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
    }
    int ans = 0;
    rep(i, N) {
        rep(j, N) { temp[j] = false; }
        dfs(i);
        rep(j, N) {
            if (temp[j]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}