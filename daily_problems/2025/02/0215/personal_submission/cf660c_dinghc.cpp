#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (auto& x : a) scanf("%d", &x);
    array<int, 3> ans{};
    for (int i = 0, j = 0, curr = 0; i < n; i++) {
        if (a[i] == 0) curr += 1;
        while (curr > k) {
            if (a[j++] == 0) curr -= 1;
        }
        ans = max(ans, array<int, 3>{i - j + 1, j, i});
    }
    printf("%d\n", ans[0]);
    for (int i = 0; i < n; i++) {
        if (i >= ans[1] && i <= ans[2]) {
            printf("1 ");
        } else {
            printf("%d ", a[i]);
        }
    }
    return 0;
}

