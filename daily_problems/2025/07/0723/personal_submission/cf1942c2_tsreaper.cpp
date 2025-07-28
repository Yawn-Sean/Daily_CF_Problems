#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, X, Y; scanf("%d%d%d", &n, &X, &Y);
    vector<int> vec;
    for (int i = 1; i <= X; i++) {
        int t; scanf("%d", &t);
        vec.push_back(t - 1);
    }
    sort(vec.begin(), vec.end());

    int ans = X - 2;
    vector<int> v1, v2;
    for (int i = 0; i < X; i++) {
        int len = (vec[(i + 1) % X] - vec[i] + n) % n;
        if (len == 2) ans++;
        else if (len % 2 == 0) v1.push_back(len);
        else if (len > 1) v2.push_back(len);
    }
    sort(v1.begin(), v1.end());

    for (int len : v1) {
        int t = len / 2 - 1;
        if (Y >= t) {
            Y -= t;
            ans += t * 2 + 1;
        } else {
            ans += Y * 2;
            Y = 0;
            break;
        }
    }

    for (int len : v2) {
        int t = len / 2;
        t = min(Y, t);
        Y -= t;
        ans += t * 2;
    }

    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
