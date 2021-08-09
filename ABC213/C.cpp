#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(x) begin(x), end(x)
template <class T> inline T chmax(T &a, const T b) {
    return a = (a < b) ? b : a;
}
template <class T> inline T chmin(T &a, const T b) {
    return a = (a > b) ? b : a;
}
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N), B(N);
    rep(i, N) { cin >> A[i] >> B[i]; }

    // 座標圧縮する
    vector<int> ys;
    rep(i, N) { ys.push_back(A[i]); }
    sort(all(ys));                       // 昇順に並べ替える
    ys.erase(unique(all(ys)), ys.end()); // ysを重複なしにする
    rep(i, N) {
        // A[i]が配列ysの何番目にあるか
        A[i] = lower_bound(all(ys), A[i]) - ys.begin();
    
    } 

    vector<int> xs;
    rep(i, N) { xs.push_back(B[i]); }
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    rep(i, N) { B[i] = lower_bound(all(xs), B[i]) - xs.begin(); }

    rep(i, N) { cout << A[i] + 1 << " " << B[i] + 1 << endl; }
    return 0;
}