/**
 *    author:  ytsmash
 *    created: 14.08.2021 21:00:16
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
    int N;
    cin >> N;
    cout << (N <= 125 ? 4 : (N <= 211 ? 6 : 8)) << "\n";
    return 0;
}