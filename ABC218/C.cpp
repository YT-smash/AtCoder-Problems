/**
 *    author:  ytsmash
 *    created: 12.09.2021 08:53:00
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
    vector<vector<char>> S(N, vector<char>(N));
    rep(i, N) {
        rep(j, N) {
            cin >> S[i][j];
        }
    }

    vector<vector<char>> T(N, vector<char>(N));
    rep(i, N) {
        rep(j, N) {
            cin >> T[i][j];
        }
    }

    bool ok = true;
    for (int i = 0; i < 4; i++) {
        int smi = N, smj = N; // s_min_i, s_min_j
        rep(j, N) {
            rep(k, N) {
                if (S[j][k] == '#') {
                    chmin(smi, j);
                    chmin(smj, k);
                }
            } 
        }

        int tmi = N, tmj = N;
        rep(j, N) {
            rep(k, N) {
                if (T[j][k] == '#') {
                    chmin(tmi, j);
                    chmin(tmj, k);
                }
            } 
        }
    }

    bool ok2 = true;
    for (int j = smi; j < N * 2; j++) {
        for (int k = smj; k < N * 2; k++) {
            int j2 = j - smi + tmi;
            
        }
    }
    return 0;
}