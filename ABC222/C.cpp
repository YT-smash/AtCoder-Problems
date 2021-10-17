/**
 *    author:  ytsmash
 *    created: 10.10.2021 17:49:00
 **/

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long ll;
typedef long double ld;
struct edge {
    int to, cost;
};
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
const long double EPS = 1e-10;
const ll INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;
vector<int> devisor(int num) {
    vector<int> ret;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            ret.push_back(i);
            if (i * i != num) {
                ret.push_back(num / i);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

vector<string> A(101);

int battle(int round, int userA, int userB) {
    char a = A[userA][round];
    char b = A[userB][round];

    if (a == b) return -1;

    if (a == 'G' && b == 'C') return userA;
    if (a == 'C' && b == 'P') return userA;
    if (a == 'P' && b == 'G') return userA;

    return userB;
} 


int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N * 2; i++) cin >> A[i];
    vector<int> win(2 * N);

    vector<int> order; // 順位
    for (int i = 0; i < N * 2; i++) order.push_back(i);

    for (int round = 0; round < M; round++) {
        for (int k = 0; k < N; k++) {
            int res = battle(round, order[k * 2], order[k * 2 + 1]);
            if (res >= 0) win[res]++;
        }
        sort(all(order), [&](int a, int b) {
            if (win[a] != win[b]) return win[a] > win[b];
            else return a < b;
        });

    }

    for (int i = 0; i < N * 2; i++) cout << order[i] + 1 << endl;
    return 0;
}