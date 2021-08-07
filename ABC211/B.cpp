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
    vector<string> s(4);
    rep(i, 4) { cin >> s[i]; }
    string ans = "Yes";

    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            if (s[i] == s[j]) {
                ans = "No";
            }
        }
    }

    cout << ans << endl;
    return 0;
}