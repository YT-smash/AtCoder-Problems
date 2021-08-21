/**
 *    author:  ytsmash
 *    created: 21.08.2021 18:41:22
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

int H, W;
vector<vector<char>> maze(510, vector<char>(510));
vector<vector<bool>> reached(510, vector<bool>(510, false));

void search(int x, int y) {
    if (x < 0 || H <= x || y < 0 || W <= y || maze[x][y] == '#') {
        return;
    }
    if (reached[x][y]) {
        return;
    }

    reached[x][y] = true;
    search(x + 1, y);
    search(x - 1, y);
    search(x, y + 1);
    search(x, y - 1);
}

int main() {
    cin >> H >> W;
    P start, goal;
    rep(i, H) {
        rep(j, W) {
            cin >> maze[i][j];
            if (maze[i][j] == 's') {
                start.first = i;
                start.second = j;
            }
            if (maze[i][j] == 'g') {
                goal.first = i;
                goal.second = j;
            }
        }
    }

    search(start.first, start.second);

    if (reached[goal.first][goal.second]) {
        cout << "Yes"
             << "\n";
    } else {
        cout << "No"
             << "\n";
    }

    return 0;
}