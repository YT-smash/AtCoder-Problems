/**
 *    author:  ytsmash
 *    created: 21.08.2021 11:53:56
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
    vector<vector<bool>> con(20, vector<bool>(20, false));
    int N, M, x, y;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        con[x - 1][y - 1] = true;
        con[y - 1][x - 1] = true;
    }

    int ans = 0;
    for (int bit = 1 << N; bit >= 0; bit--) {
        int t = bitset<32>(bit).count();  // 派閥の数
        if (t <= ans) {
            continue;
        }

        bool flag = true;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if ((bit & (1 << i)) && (bit & (1 << j)) && !con[i][j] &&
                    !con[j][i]) {
                    flag = false;
                }
            }
        }

        if (flag) {
            ans = t;
        }
    }

    cout << ans << "\n";
    return 0;
}