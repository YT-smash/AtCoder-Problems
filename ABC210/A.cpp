/**
*    author:  ytsmash
*    created: 11.08.2021 21:57:57
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int N, A, X, Y;
    cin >> N >> A >> X >> Y;
    if (N < A) {
        cout << N * X << "\n";
    }
    else {
        cout << A * X + Y * (N - A) << "\n";
    }
    return 0;
}