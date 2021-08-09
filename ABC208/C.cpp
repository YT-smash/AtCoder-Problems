#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T & a, const T b) { return a = (a > b) ? b : a; }

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
    int N;
    ll K;
    cin >> N >> K;

    vector<int> a(N);
    rep(i, N) { cin >> a[i]; }

    vector<int> order(N);
    iota(order.begin(), order.end(), 0); // order[i] = i
    sort(order.begin(), order.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> answer(N, K / N);
    rep(i, K % N) { answer[order[i]]++; }

    for (auto&x : answer) {
        cout << x << endl;
    }

    return 0;
}