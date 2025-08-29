#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    scanf("%d", &x);
    int ans = *ranges::partition_point(views::iota(1, 100), [&] (int k) {
        int n = k * 2 - 1;
        return x > (n * n + 1) / 2;
    });
    if (x == 3) {
        ans = 5;
    } else {
        ans = ans * 2 - 1;
    }
    printf("%d\n", ans);
    return 0;
}

