/**
 *    author:  ytsmash
 *    created: 05.09.2021 14:29:38
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

int main() {
    int Q;
    cin >> Q;
    queue<ll> q1;
    priority_queue<ll, vector<ll>, greater<ll>> q2;

    rep(i, Q) {
        int c;
        cin >> c;
        if (c == 1) {
            ll x;
            cin >> x;
            q1.push(x);
        }
        if (c == 2) {
            if (q2.empty()) {
                ll x = q1.front();
                cout << x << "\n";
                q1.pop();
            } else {
                ll x = q2.top();
                cout << x << "\n";
                q2.pop();
            }
        }
        if (c == 3) {
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    return 0;
}