/**
 *    author:  ytsmash
 *    created: 22.08.2021 08:30:06
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
    ll N;
    cin >> N;
    for (int i = 0; i < 100; i++) {
        if ((1ll << i) > N) {
            cout << i - 1 << "\n";
            break;
        }
    }
    return 0;
}