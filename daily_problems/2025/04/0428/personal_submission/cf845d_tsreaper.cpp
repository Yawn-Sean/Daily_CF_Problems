#include <bits/stdc++.h>
#define INF ((int) 1e9)
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int ans = 0, x = 0;
    vector<int> X, Y;
    X.push_back(INF); Y.push_back(1);
    for (int i = 1; i <= n; i++) {
        int op; scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
        } else if (op == 2) {
            while (Y.back() == 0) ans++, Y.pop_back();
        } else if (op == 3) {
            int t; scanf("%d", &t);
            X.push_back(t);
        } else if (op == 4) {
            Y.push_back(1);
        } else if (op == 5) {
            X.push_back(INF);
        } else if (op == 6) {
            Y.push_back(0);
        }
        while (X.back() < x) ans++, X.pop_back();
    }
    printf("%d\n", ans);
    return 0;
}
