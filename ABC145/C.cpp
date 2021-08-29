/**
 *    author:  ytsmash
 *    created: 29.08.2021 10:43:54
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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

int main() {
    int N;
    cin >> N;
    vector<int> x(8), y(8);
    rep(i, N) cin >> x[i] >> y[i];

    vector<int> order(N);
    iota(all(order), 0);
    ld dist_sum = 0;
    do {
        for (int i = 0; i < N - 1; i++) {
            int a = order[i];
            int b = order[i + 1];

            ld dx = x[a] - x[b];
            ld dy = y[a] - y[b];

            dist_sum += sqrt(dx * dx + dy * dy);
        }
    } while (next_permutation(all(order)));
    rep(i, N) dist_sum /= (i + 1);
    printf("%.10Lf\n", dist_sum);
    return 0;
}