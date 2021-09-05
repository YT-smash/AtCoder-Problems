/**
 *    author:  ytsmash
 *    created: 04.09.2021 13:00:46
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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N), K(Q);
    rep(i, N) cin >> A[i];

    // A[0] ~ A[N - 1]のいずれとも異なる正整数を「良い整数」とする
    vector<ll> cnt(N); // cnt[i]はA[i]以下の良い整数の個数
    rep(i, N) cnt[i] = A[i] - i - 1;

    rep(i, Q) {
        ll K;
        cin >> K;
        if (K > cnt[N - 1]) cout << A[N - 1] + K - cnt[N - 1] << "\n";
        else {
            int ind = lower_bound(all(cnt), K) - cnt.begin();
            cout << A[ind - 1] + K - cnt[ind - 1] << "\n";
        }
    }

    return 0;
}