/**
 *    author:  ytsmash
 *    created: 16.10.2021 20:31:53
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
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<int> order;
    rep(i, N) order.push_back(i);
    sort(all(order), [&](int i, int j) {
        if (i >= j) return A[order[i]] >= A[order[j]];
    });

    ll gol = 1, sil = 0;
    rep(i, N / 2) {
        ll sum = 0;
        sum += gol * A[order[i]];
        sum /= A[order[N - i - 1]];
        if (sum > gol) {
            gol = sum;
            order[i] = -1;
            order[N - i - 1] = -1;
        }
        else break;
    }

    rep(i, N) {
        if (order[i] == -1) cout << 1 << " ";
        else cout << 0 << " ";
    }
    
    return 0;
}