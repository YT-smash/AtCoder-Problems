#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define for(i, m, n) for(int i = m;i < n;i++)
#define all(n) begin(n),end(n)
#define in(a, x, b) (a<=x && x<b)
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T & a, const T b) { return a = (a > b) ? b : a; }

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
    INIT;

    int A;
    int B;
    cin >> A >> B;

    if (A > 0 && B == 0) {
        cout << "Gold" << endl;
    } else if (A == 0 && B > 0) {
        cout << "Silver" << endl;
    } else if (A > 0 && B > 0) {
        cout << "Alloy" << endl;
    }
    return 0;
}