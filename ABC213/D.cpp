#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) begin(x), end(x)
template <class T>
inline T chmax(T &a, const T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline T chmin(T &a, const T b) {
    return a = (a > b) ? b : a;
}
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

vector<vector<int>> to;  // to[a]は都市a+1の隣接都市のリスト
vector<int> ans;         // 答えの配列

// dfs(depth-first search)
void dfs(int crr, int pre = -1) {
    ans.push_back(crr);  // vから始める
    for (int nxt : to[crr]) {
        if (nxt != pre) {
            dfs(nxt, crr);
            ans.push_back(crr);  // 親に戻る
        }
    }
}

int main() {
    int n;
    cin >> n;
    to.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;  // 都市a
        b--;
        to[a].push_back(b);  // aとbは隣接しあっている
        to[b].push_back(a);
    }
    rep(i, n) { sort(all(to[i])); }  // 隣接リストを昇順に並べ替えておく
    dfs(0);
    for (int v : ans) {
        cout << v + 1 << endl;
    }
    return 0;
}