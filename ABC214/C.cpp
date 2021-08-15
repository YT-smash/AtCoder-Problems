/**
 *    author:  ytsmash
 *    created: 14.08.2021 21:08:14
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
    vector<int> S(N), T(N);
    rep(i, N) { cin >> S[i]; }
    rep(i, N) { cin >> T[i]; }

    vector<int> time = T;
    rep(i, 2 * N) {
        time[(i + 1) % N] = min(time[(i + 1) % N], time[i % N] + S[i % N]);
    }

    rep(i, N) { cout << time[i] << "\n"; }
    return 0;
}