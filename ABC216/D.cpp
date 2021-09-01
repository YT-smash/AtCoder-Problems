/**
 *    author:  ytsmash
 *    created: 01.09.2021 08:41:53
 **/

#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int N, M;
    cin >> N >> M;
    queue<int> que;
    vector<queue<int>> A(M);
    vector<vector<int>> mem(N);
    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            A[i].push(a - 1);
        }
        mem[A[i].front()].push_back(i);  // 一番上の色をとっていく
    }
    rep(i, N) {
        // 同じ色が2個あるとき
        if (mem[i].size() == 2) {
            que.push(i);  // 取り除く色を記録していく
        }
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        // 色nowのものpに対して
        for (auto p : mem[now]) {
            A[p].pop(); // 取り除く
            // 取り除いてまだ残ってるなら
            if (!A[p].empty()) {
                mem[A[p].front()].push_back(p);
                if (mem[A[p].front()].size() == 2) {
                    que.push(A[p].front());
                }
            }
        }
    }
    for (auto p : A) {
        if (!p.empty()) {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}