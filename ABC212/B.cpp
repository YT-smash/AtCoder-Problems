#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

    vector<int> X(4);
    int num;
    cin >> num;

    X[0] = num / 1000;
    num = num % 1000;
    X[1] = num / 100;
    num = num % 100;
    X[2] = num / 10;
    num = num % 10;
    X[3] = num;

    if (X[0] == X[1] && X[1] == X[2] && X[2] == X[3]) {
        cout << "Weak" << endl;
    } else if (X[1] == (X[0] + 1) % 10 && X[2] == (X[1] + 1) % 10 && X[3] == (X[2] + 1) % 10) {
        cout << "Weak" << endl;
    } else {
        cout << "Strong" << endl;
    }

    return 0;
}