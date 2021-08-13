/**
 *    author:  ytsmash
 *    created: 13.08.2021 09:26:24
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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << c << "\n";
    } else if (b == c) {
        cout << a << "\n";
    } else if (c == a) {
        cout << b << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}