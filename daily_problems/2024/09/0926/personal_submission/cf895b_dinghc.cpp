#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int a[N];

int main() {
    int n, x, k;
    scanf("%d%d%d", &n, &x, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    auto count = [&] (int a, int b) -> int {
        int r = b % x;
        if (b - r < a) return 0;
        return (b - r - a + x) / x;
    };
    sort(begin(a), begin(a) + n);
    long long ans = 0;
    map<int, int> freq;
    for (int r = 0, l1 = 0, l2 = 0; r < n; r++) {
        if (k == 1 && a[r] % x == 0 || k == 0 && a[r] % x != 0) {
            freq[a[r]]++;
        }
        while (l1 <= r && count(a[l1], a[r]) > k) {
            l1++;
        }
        while (l2 <= r && count(a[l2], a[r]) >= k) {
            l2++;
        }
        ans += l2 - l1;
    }
    if (k == 1 || k == 0) {
        for (auto& [_, cnt] : freq) {
            ans -= 1LL* cnt * (cnt + 1) / 2;
            ans += 1LL* cnt * cnt;
        }
    }
    printf("%lld", ans);
    return 0;
}

