#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int s = 1e6;

void solve() {
    int n, x, need = 0;
    scanf("%d", &n);
    vector<int> use(s+1, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        use[x] = 1;
    }
    vector<pair<int, int>> left;
    printf("%d\n", n);;
    for (int i = 1; i <= s/2; ++i) {
        if (!use[i] && !use[s+1-i]) {
            left.emplace_back(i, s+1-i);
        } else if (use[i] && use[s+1-i]) {
            need++;
        } else if (use[i]) {
            printf("%d ", s+1-i);
        } else {
            printf("%d ", i);
        }
    }
    for (int i = 0; i < need; ++i) {
        printf("%d %d ", left[i].first, left[i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
