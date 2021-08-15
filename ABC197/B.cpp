/**
 *    author:  ytsmash
 *    created: 15.08.2021 11:06:46
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
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<string> S(H);
    rep(i, H) { cin >> S[i]; }

    int ans = 0;
    for (int i = X - 1; i >= 0; i--) {
        if (S[i][Y - 1] == '.') {
            ans++;
        } else {
            break;
        }
    }
    for (int i = X - 1; i <= H - 1; i++) {
        if (S[i][Y - 1] == '.') {
            ans++;
        } else {
            break;
        }
    }
    for (int i = Y - 1; i >= 0; i--) {
        if (S[X - 1][i] == '.') {
            ans++;
        } else {
            break;
        }
    }
    for (int i = Y - 1; i <= W - 1; i++) {
        if (S[X - 1][i] == '.') {
            ans++;
        } else {
            break;
        }
    }

    cout << ans - 3 << "\n";
    return 0;
}