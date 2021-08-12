/**
 *    author:  ytsmash
 *    created: 12.08.2021 11:44:22
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
    int value = (108 * N) / 100;
    if (value < 206) {
        cout << "Yay!"
             << "\n";
    } else if (value == 206) {
        cout << "so-so"
             << "\n";
    } else {
        cout << ":("
             << "\n";
    }
    return 0;
}