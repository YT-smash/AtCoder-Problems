#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
template <class T> inline T chmax(T &a, const T b) {
    return a = (a < b) ? b : a;
}
template <class T> inline T chmin(T &a, const T b) {
    return a = (a > b) ? b : a;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int facto(int n) {
    int x = 1;
    while(n > 1) {
        x = x * n;
        n--;
    }

    return x;
}

int main() {
    int P;
    cin >> P;
    int ans = 0;

    for(int i = 10; i > 0; i--) {
        ans += (int)(P / facto(i));
        P %= facto(i);
    }
    cout << ans << endl;
    return 0;
}