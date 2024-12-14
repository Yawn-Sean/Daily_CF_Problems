#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    auto ref = [] (int x) -> long long {
        long long re = 0, pw = 1;
        while (x) {
            re = re + pw * (9 - x % 10);
            x /= 10;
            pw *= 10;
        }
        return re;
    };
    long long ans = max(1LL * l * ref(l), 1LL * r * ref(r));
    long long s = 5;
    int q = l / 10;
    while (q) {
        s *= 10;
        q /= 10;
    }
    while (s - 1 <= r) {
        if (s - 1 >= l) ans = max(ans, 1LL * (s - 1) * ref(s - 1));
        s *= 10;
    }
    printf("%lld\n", ans);
    return 0;
}

