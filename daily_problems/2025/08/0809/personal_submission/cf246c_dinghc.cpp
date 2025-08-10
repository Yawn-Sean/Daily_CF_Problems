#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (auto& x : a) {
        scanf("%d", &x);
    }
    ranges::sort(a);
    int m = 0;
    while (k) {
        vector<int> det;
        for (int i = n - 1; i >= n - m; i--) {
            det.push_back(a[i]);
        }
        for (int i = 0; k > 0 && i < n - m; i++) {
            printf("%d ", m + 1);
            for (auto & x : det) {
                printf("%d ", x);
            }
            printf("%d\n", a[i]);
            k -= 1;
        }
        m += 1;
    }
    return 0;
}

