#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T & a, const T b) { return a = (a > b) ? b : a; }

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
    INIT;

    ll N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> B(M);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    ll min = INF;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (min > abs(A[i] - B[j])) {
                min = abs(A[i] - B[j]);
            }
        }
    }

    cout << min << endl;
    return 0;
}