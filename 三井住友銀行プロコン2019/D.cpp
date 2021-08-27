/**
 *    author:  ytsmash
 *    created: 26.08.2021 21:31:44
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
using P = pair<int, int>;

int main() {
    int N;
    string S;
	cin >> N >> S;
    int cnt = 0;
	for (int i = 0; i < 1000; i++) {
		int c[3] = {i / 100, (i / 10) % 10, i % 10};
		int f = 0;
		for (int j = 0; j < N; j++) {
			if (S[j] == ('0' + c[f])) f++;
			if (f == 3) break;
		}
		if (f == 3) cnt++;
	}
	cout << cnt << endl;
	return 0;
}