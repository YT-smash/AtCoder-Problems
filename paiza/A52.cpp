/**
 *    author:  ytsmash
 *    created: 29.08.2021 11:57:12
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long double PI = acos(-1.0L);
using P = pair<int, int>;
vector<int> devisor(int num) { vector<int> ret; for (int i = 1; i * i <= num; i++) { if (num % i == 0) { ret.push_back(i); if (i * i != num) { ret.push_back(num / i); } } } sort(ret.begin(), ret.end()); return ret; }
vector<pair<ll, ll>> prime_factorize(ll N) { vector<pair<ll, ll>> res; for (ll a = 2; a * a <= N; ++a) { if (N % a != 0) continue; ll ex = 0; while (N % a == 0) { ++ex; N /= a; } res.push_back({a, ex}); } if (N != 1) res.push_back({N, 1}); return res; }

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<bool> dp(N * max(A, B));
    dp[0] = true;
    dp[N] = true;
    for (int i = 0; i <= N; i++) {
        if (dp[i]) {
            dp[i + A] = true;
            dp[i + B] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (!dp[i]) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}