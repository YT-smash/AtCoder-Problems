#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n); // 0で初期化されている
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    
    vector<int> cnt(n+1);
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    
    long long ans = 0;
    for (int j = 0; j < n; ++j) ans += cnt[b[c[j]-1]];
    cout << ans << endl;
}
