/**
 *    author:  ytsmash
 *    created: 04.10.2021 11:40:02
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
    string N;
    cin >> N;
    sort(all(N));

    int ans = 0;
    do{
        for (int i = 0; i < N.size(); i++) {
            int l = 0, r = 0;
            for (int j = 0; j < i; j++) l = l * 10 + N[j] - '0';
            for (int j = i; j < N.size(); j++) r = r * 10 + N[j] - '0';
            chmax(ans, l * r);
        }
    } while(next_permutation(all(N)));
    cout << ans << endl;
    return 0;
}