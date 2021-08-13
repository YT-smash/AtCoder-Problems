/**
 *    author:  ytsmash
 *    created: 12.08.2021 20:03:56
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
    int x, y;
    cin >> x >> y;
    int ans = (6 - x - y) % 3;
    cout << ans << "\n";
    return 0;
}