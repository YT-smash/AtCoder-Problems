/**
 *    author:  ytsmash
 *    created: 26.08.2021 09:04:17
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    string S;
    cin >> S;
    int N = S.length();
    string T = "ATCG";

    int ans = 0;
    for (int L = 0; L < N; L++) {
        for (int R = L; R < N; R++) {
            bool ok = true;
            for (int i = L; i < R + 1; i++) {
                // 文字S[i]が文字列Tにないならフラグをfalseにする
                if (T.find(S[i]) == string::npos) {
                    ok = false;
                } 
            }
            if (ok) {
                chmax(ans, R - L + 1);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}