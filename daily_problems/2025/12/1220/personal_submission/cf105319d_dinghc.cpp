#include <bits/stdc++.h>

using namespace std;
constexpr int A = 30;
constexpr int N = 1e6;
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    array<int, 2> x[A]{};
    auto f = [&] (int a1, int a2, int delta = 1) -> void {
        for (int d = A - 1; d >= 0; d--) {
            if ((a1 >> d & 1) < (a2 >> d & 1)) {
                x[d][0] += delta;
                break;
            } else if ((a1 >> d & 1) > (a2 >> d & 1)) {
                x[d][1] += delta;
                break;
            }
        }
    };
    auto check = [&] () -> bool {
        for (int d = 0; d < A; d++) {
            if (x[d][0] && x[d][1]) return false;
        }
        return true;
    };
    long long ans = 1;
    for (int i = 1, j = 0; i < n; i++) {
        f(a[i - 1], a[i]);
        while (j < i && !check()) {
            f(a[j], a[j + 1], -1);
            j += 1;
        }
        ans += i - j + 1;
    }
    printf("%lld\n", ans);
    return 0;
}

