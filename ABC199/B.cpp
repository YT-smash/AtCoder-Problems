#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    
    int ans = max(0, b[0]-a[0]+1);
    cout << ans << endl;
    return 0;
}
