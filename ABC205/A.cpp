/**
 *    author:  ytsmash
 *    created: 12.08.2021 16:23:03
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
    int A, B;
    cin >> A >> B;
    double ans = ((double)(A * B)) / 100;
    cout << ans << "\n";
    return 0;
}