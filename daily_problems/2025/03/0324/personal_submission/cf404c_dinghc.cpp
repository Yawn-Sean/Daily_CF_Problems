#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int>> b(n);
    for (int i = 1, d; i <= n; i++) {
        cin >> d;
        b[d].push_back(i);
    }
    if (b[0].size() != 1) {
        printf("-1\n");
    } else {
        size_t cnt = k;
        for (int curr = 1; curr < n; curr += 1) {
            if (b[curr].size() > cnt) {
                printf("-1\n");
                return 0;
            }
            cnt = b[curr].size() * (k - 1);
        }
        printf("%d\n", n - 1);
        for (int curr = 1; curr < n; curr += 1) {
            for (int i = 0; i < b[curr].size(); i++) {
                printf("%d %d\n", b[curr - 1][i / (curr == 1 ? k : k - 1)], b[curr][i]);
            }
        }
    }
    return 0;
}
