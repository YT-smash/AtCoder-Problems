/**
 *    author:  ytsmash
 *    created: 13.08.2021 09:57:21
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    rep(i, 10000) {
        vector<bool> flag(10);
        int X = i;
        rep(j, 4) {
            flag[X % 10] = true;
            X /= 10;
        }
        bool flag2 = true;
        rep (j, 10) {
            if(S[j] == 'o' && !flag[j]) flag2 = false;
            if(S[i] == 'x' && flag[j]) flag2 = false;
        }
        ans += flag2;
    }
    return 0;
}