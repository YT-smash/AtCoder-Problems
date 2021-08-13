/**
 *    author:  ytsmash
 *    created: 12.08.2021 20:14:37
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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }
    
    int ans = 0;
    rep(i, N) { ans += max(0, A[i] - 10); }
    cout << ans << "\n";
    return 0;
}