/**
 *    author:  ytsmash
 *    created: 26.08.2021 13:46:09
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int n, x;
    cin >> n >> x;
    while (n != 0 || x != 0) {
        int ans = 0;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (i + j + k == x) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";

        cin >> n >> x;
    }
   
    return 0;
}