#include <bits/stdc++.h>
using namespace std;

int N;
string S, T;

int main() {
    cin >> N >> S >> T;
    
    vector<int> a, b;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') a.push_back(i);
        if (T[i] == '0') b.push_back(i);
    }
    
    if ((int)a.size() != (int)b.size()) {
        cout << "-1" << endl;
        return 0;
    }
    
    int Answer = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] != b[i]) ++Answer;
    }
    
    cout << Answer << endl;
    return 0;
}
