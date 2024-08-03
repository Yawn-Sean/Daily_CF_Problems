#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, d; scanf("%d%d", &X, &d);
    vector<long long> ans;
    long long now = 1;
    while (X > 0) {
        for (int i = 30; i >= 1; i--) if ((1 << i) - 1 <= X) {
            X -= (1 << i) - 1;
            for (int j = 1; j <= i; j++) ans.push_back(now);
            break;
        }
        now += d + 1;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%lld%c", ans[i], "\n "[i + 1 < ans.size()]);
    return 0;
}
