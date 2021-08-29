/**
 *    author:  ytsmash
 *    created: 28.08.2021 19:04:22
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long double EPS = 1e-10;
const ll INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    vector<bool> feasible(2000 * 20 + 10, false);
    for (int i = 0; i < (1 << n); i++) {
        bitset<20> bit(i);
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (bit.test(j)) {
                sum += A[j];
            }
        }
        feasible[sum] = true;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        if (feasible[m]) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
        
    return 0;
}