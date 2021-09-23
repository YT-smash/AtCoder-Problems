/**
 *    author:  ytsmash
 *    created: 23.09.2021 13:43:46
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
    string S;
    cin >> N >> S;

    vector<int> E(N), W(N);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'E') E[i]++;
        else W[i]++;
    }

    for (int i = 1; i <= N; i++) {
        E[i] += E[i - 1];
        W[i] += W[i - 1];
    }
    int ans = N + 10;
    
    for (int i = 0; i < N; i++) {
        int sum = 0;
        if (i) sum += W[i - 1];
        sum += E[N - 1] - E[i];
        chmin(ans, sum);
    }
    
    cout << ans << endl;
    return 0;
}