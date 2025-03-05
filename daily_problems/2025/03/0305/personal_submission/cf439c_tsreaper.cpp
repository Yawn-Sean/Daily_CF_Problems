#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, X, Y; scanf("%d%d%d", &n, &X, &Y);
    X -= Y;

    vector<vector<int>> ans;
    vector<int> odd, even;
    int sm = X % 2;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x & 1) {
            if (X > 0) ans.push_back({x}), X--;
            else odd.push_back(x);
        } else {
            if (Y > 0) ans.push_back({x}), Y--;
            else even.push_back(x);
        }
        sm ^= x & 1;
    }

    if (sm) { printf("NO\n"); return 0; }
    if (X > 0) { printf("NO\n"); return 0; }
    if (Y > 0) {
        if (odd.size() < Y * 2) { printf("NO\n"); return 0; }
        while (Y > 0) {
            int x = odd.back(); odd.pop_back();
            int y = odd.back(); odd.pop_back();
            ans.push_back({x, y});
            Y--;
        }
    }
    for (int x : odd) ans.back().push_back(x);
    for (int x : even) ans.back().push_back(x);
    printf("YES\n");
    for (auto &vec : ans) {
        printf("%d", vec.size());
        for (int x : vec) printf(" %d", x);
        printf("\n");
    }
    return 0;
}
