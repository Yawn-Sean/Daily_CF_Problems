#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using vi = vector<int>;

vi x[2], y[2], b[2];

bool check(int i, int j, int ind) {
    if (ind == 0)
        return i >= x[ind][0] && i <= x[ind][3] && j >= y[ind][0] && j <= y[ind][3];
    else
        return j - i >= b[0][0] && j - i <= b[0][3] && i + j >= b[1][0] && i + j <= b[1][3];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 4; i++) {
            int a, b;
            cin >> a >> b;
            x[j].push_back(a);
            y[j].push_back(b);
        }

    for (int i = 0; i < 4; i++) {
        b[0].push_back(y[1][i] - x[1][i]);
        b[1].push_back(y[1][i] + x[1][i]);
    }
    for (int j = 0; j < 2; j++) {
        sort(begin(b[j]), end(b[j]));
        sort(begin(x[j]), end(x[j]));
        sort(begin(y[j]), end(y[j]));
    }

    for (int i = -100; i <= 100; i++)
        for (int j = -100; j <= 100; j++)
            if (check(i, j, 0) && check(i, j, 1)) {
                cout << "YES" << endl;
                return 0;
            }
    cout << "NO" << endl;
    return 0;
}
