#include <bits/stdc++.h>
 
using namespace std;
constexpr int INF = 1e9;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> w1, w2;
    for (int i = 0, t, w; i < n; i++) {
        scanf("%d%d", &t, &w);
        if (t == 1) w1.push_back(w);
        else w2.push_back(w);
    }
    ranges::sort(w1);
    int n1 = w1.size();
    vector<int> sum1(n1 + 1, 0);
    for (int i = 1; i <= n1; i++) sum1[i] = sum1[i - 1] + w1[i - 1];
    ranges::sort(w2);
    int n2 = w2.size();
    vector<int> sum2(n2 + 1, 0);
    for (int i = 1; i <= n2; i++) sum2[i] = sum2[i - 1] + w2[i - 1];
    int ans = INF;
    for (int v1 = 0; v1 <= n1; v1++) {
        for (int v2 = 0; v2 <= n2; v2++) {
            if (sum1[v1] + sum2[v2] <= n1 - v1 + (n2 - v2) * 2) {
                ans = min(ans, n1 - v1 + (n2 - v2) * 2);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

