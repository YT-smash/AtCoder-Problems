/**
 *    author:  ytsmash
 *    created: 11.08.2021 22:06:39
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
    int A, B;
    cin >> A >> B;
    int ans;
    if (B < A) {
        ans = 0;
    } else {
        ans = B - A + 1;
    }
    cout << ans << "\n";
    return 0;
}