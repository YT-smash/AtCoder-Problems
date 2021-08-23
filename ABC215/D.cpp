/**
 *    author:  ytsmash
 *    created: 22.08.2021 08:42:58
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

// xの素因数分解(計算量はO(√x))
// a全体に対して行うので計算量は最悪でO(√max(a))
vector<int> pfact(int x) {
    vector<int> res;  // resはxの素因数のリスト
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            res.push_back(i);
        }
    }
    if (x != 1) {
        res.push_back(x);
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> fl(1000000, true);
    rep(i, N) {
        int a;
        cin >> a;
        vector<int> v = pfact(a);  // vはaの素因数全体

        // aの各素因数に対して、その倍数を全部はじく
        for (int num : v) {
            if (fl[num]) {
                for (int j = num; j < 1000000; j += num) {
                    fl[j] = false;
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= M; i++) {
        if (fl[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << "\n";
    }
    return 0;
}