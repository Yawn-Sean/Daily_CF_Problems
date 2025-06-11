#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto& x : a) {
        scanf("%d", &x);
    }
    vector<bool> b(n, false);
    b[0] = true;
    b[n - 1] = true;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == a[i + 1] || a[i] == a[i - 1]) {
            b[i] = true;
        }
    }
    int ans = 0;
    int i = 0;
    do {
        while (i < n && b[i]) i++;
        if (i == n) break;
        int j = i;
        while (!b[j]) j++;
        ans = max(ans, (j - i + 1) / 2);
        if (a[i - 1] == a[j]) {
            for (int k = i; k < j; k++) {
                a[k] = a[i - 1];
            }
        } else {
            for (int k = i; k < j; k++) {
                if (k - i < (j - i + 1) / 2) a[k] = a[i - 1];
                else a[k] = a[j];
            }
        }
        i = j;
    } while (true);
    printf("%d\n", ans);
    for (auto& x : a) {
        printf("%d ", x);
    }
    return 0;
}

