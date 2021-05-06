#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A;
    int B;
    int C;
    cin >> A >> B >> C;
    if (A * A + B * B < C* C) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}
