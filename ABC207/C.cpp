/**
 *    author:  ytsmash
 *    created: 12.08.2021 19:23:28
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
    vector<double> l(N), r(N);
    /**
     * 整数の開区間は閉区間にせよ
     */
    rep(i, N) {
        int t;
        cin >> t >> l[i] >> r[i];
        t--;
        if (t & 1) r[i] -= 0.5;
        if (t & 2) l[i] += 0.5;
    }

    /**
     * 2つの開区間[a,b],[c,d]が共通部分を持つための必要十分条件は、max(a,c) <= min(b,d)
     */
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (max(l[i], l[j]) <= min(r[i], r[j])) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}