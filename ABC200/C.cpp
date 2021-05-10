#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    long long answer = 0;
    vector<long long> c(200, 0); 
    
    for (int i = 0; i < N; ++i) {
        ++c[A[i] % 200];
    }
    
    for (int i = 0; i < 200; ++i) {
        if (c[i] > 1) {
            answer += (int) c[i] * (c[i] - 1) / 2;
        }
    }
    
    cout << answer;
}
