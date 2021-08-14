/**
 *    author:  ytsmash
 *    created: 13.08.2021 15:39:31
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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
    vector<int> Row(H), Column(W);
    rep(i, H) {
        rep(j, W) { cin >> A[i][j]; }
    }
    rep(i, H) {
        rep(j, W) {
            Row[i] += A[i][j];
            Column[j] += A[i][j];
        }
    }
    rep(i, H) {
        rep(j, W) { B[i][j] = Row[i] + Column[j] - A[i][j]; }
    }

    rep(i, H) {
        rep(j, W) {
            cout << B[i][j] << "\n";
        }
    }

    return 0;
}