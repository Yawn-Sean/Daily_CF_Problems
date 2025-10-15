#include <bits/stdc++.h>
using namespace std;

int main() {
    int t0, t1, t2, a, b; scanf("%d%d%d%d%d", &t1, &t2, &a, &b, &t0);
    if (t1 == t2) { printf("%d %d\n", a, b); return 0; }

    auto check = [&](int x, int y) {
        long long left = 1LL * t1 * x + 1LL * t2 * y;
        long long right = 1LL * t0 * (x + y);
        return left >= right;
    };

    int ans1 = 0, ans2 = b;
    for (int i = 0; i <= a; i++) {
        if (!check(i, b)) continue;
        int head = (i ? 0 : 1), tail = b;
        while (head < tail) {
            int mid = (head + tail) >> 1;
            if (check(i, mid)) tail = mid;
            else head = mid + 1;
        }
        long long left = (1LL * t1 * i + 1LL * t2 * head) * (ans1 + ans2);
        long long right = (1LL * t1 * ans1 + 1LL * t2 * ans2) * (i + head);
        if (left < right || (left == right && i + head > ans1 + ans2)) ans1 = i, ans2 = head;
    }
    printf("%d %d\n", ans1, ans2);
}
