/**
 *    author:  ytsmash
 *    created: 14.08.2021 21:05:10
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
    int S, T;
    cin >> S >> T;
    int ans = 0;
    for (int a = 0; a <= S; a++) {
        for (int b = 0; b <= S - a; b++) {
            for (int c = 0; c <= S - a - b; c++) {
                if (a * b * c <= T) ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}