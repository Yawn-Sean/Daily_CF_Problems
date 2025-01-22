#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> a(m);
        unordered_map<int, int> freq;
        int x = 0;
        int m2 = (m + 1) / 2;
        for (int i = 0, k; i < m; i++) {
            scanf("%d", &k);
            a[i] = vector<int>(k);
            for (auto& b : a[i]) scanf("%d", &b);
            if (++freq[a[i][0]] > m2) x = a[i][0];
        }
        if (x) {
            int cnt = freq[x];
            for (int i = 0; cnt > m2 && i < m; i++) {
                if (x == a[i][0] && a[i].size() > 1) {
                    swap(a[i][0], a[i][1]);
                    cnt -= 1;
                }
            }
            if (cnt > m2) {
                printf("NO\n");
                continue;
            }
        }
        printf("YES\n");
        for (int i = 0; i < m; i++) {
            printf("%d ", a[i][0]);
        }
        printf("\n");
    }
    return 0;
}

