#include <bits/stdc++.h>
using namespace std;

void solveE() {
    int n;
    cin >> n;
    vector<int> l(n), p(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> p[i];
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return (100 - p[b]) * p[a] * l[a] > (100 - p[a]) * p[b] * l[b];
    });
    double ans = 0, like = 0;
    for (int i = 0; i < n; i++) {
        ans += l[idx[i]] + (100 - p[idx[i]]) * like / 100.0;
        like += l[idx[i]] * p[idx[i]] / 100.0;
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    solveE();
}
