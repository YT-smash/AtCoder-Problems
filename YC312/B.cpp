/**
 *    author:  ytsmash
 *    created: 03.09.2021 21:27:12
 **/

#include <bits/stdc++.h>
using namespace std;

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

ll mpow(ll x, ll y) {
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret *= x; // yの最下位ビットが1ならばx^(2^i)をかける
        x *= x;
        y >>= 1; // yを右シフト
    }
    return ret;
}

int main() {
    ll n;
    cin >> n;
    if (n < 4LL) {
        cout << n << endl;
    } else {
        ll ans = INF;
        for (ll j = 2; j <= log2(n); j++) {
            ll i = pow(n, 1.0 / j); // iはnのj乗根の整数部分としたいがpowは誤差が生じる
            while (pow(i + 1, j) <= n) i++; // なので誤差を修正する
            ll k = n - mpow(i, j);
            chmin(ans, i + j + k);
        }
        cout << ans << endl;
    }

    return 0;
}