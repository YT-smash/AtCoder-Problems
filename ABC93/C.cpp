/**
 *    author:  ytsmash
 *    created: 11.09.2021 17:44:33
 **/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long ll;
typedef long double ld;
struct edge { int to, cost; };
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long double EPS = 1e-10;
const ll INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;
vector<int> devisor(int num) { vector<int> ret; for (int i = 1; i * i <= num; i++) { if (num % i == 0) { ret.push_back(i); if (i * i != num) { ret.push_back(num / i); } } } sort(ret.begin(), ret.end()); return ret; }
vector<pair<ll, ll>> prime_factorize(ll N) { vector<pair<ll, ll>> res; for (ll a = 2; a * a <= N; ++a) { if (N % a != 0) continue; ll ex = 0; while (N % a == 0) { ++ex; N /= a; } res.push_back({a, ex}); } if (N != 1) res.push_back({N, 1}); return res; }

int main() {
    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];

    int odd = 0, even = 0;
    rep(i, 3) {
        if (A[i] % 2 == 0) even++;
        else odd++; 
    }
    
    int ans = 0;
    if (odd == 2) {
        ans++;
        rep(i, 3) {
            if (A[i] % 2 == 1) A[i]++;
        }
    }
    else if (even == 2) {
        ans++;
        rep(i, 3) {
            if (A[i] % 2 == 0) A[i]++;
        }
    }

    int ma = max({A[0], A[1], A[2]});
    rep(i, 3) ans += (ma - A[i]) / 2;
    cout << ans << "\n"; 

    return 0;
}