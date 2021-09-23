/**
 *    author:  ytsmash
 *    created: 13.09.2021 21:06:49
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
    int W, H, N;
    cin >> W >> H >> N;

    int minx = W, miny = H, maxx = 0, maxy = 0;
    rep(i, N) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) chmax(maxx, x);
        else if (a == 2) chmin(minx, x);
        else if (a == 3) chmax(maxy, y);
        else if (a == 4) chmin(miny, y);
    }
    if (maxx < minx && maxy < miny) cout << (minx - maxx) * (miny - maxy) << "\n";
    else cout << 0 << "\n";
    return 0;
}