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
    string S;
    cin >> N >> S;

    for(int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '1') {
            if (i % 2== 0)
                cout << "Takahashi" << endl;
            else
                cout << "Aoki" << endl;
            break;
        }
    }
    return 0;
}