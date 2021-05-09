#include <bits/stdc++.h>
using namespace std;

void output(int s) {
    vector<int> a;
    int i = 1;
    while (s) {
        if (S&1) a.push_back(i);
        ++i;
        s >>= 1;
    }
    cout << a.size();
    for (int x : a) cout << " " << x;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    n = min(n, 8);
    vector<int> st(200);
    for (int s = 1; s < (1<<n)); ++s) {
        int x = 0;
        for (int i = 0; i < n; ++i) {
            if (s>>i & 1) x = (x + a[i]) % 200;
            if (st[x] == 0) st[x] = s;
            else {
                cout << "Yes" << endl;
                output(s);
                output(st[x]);
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
