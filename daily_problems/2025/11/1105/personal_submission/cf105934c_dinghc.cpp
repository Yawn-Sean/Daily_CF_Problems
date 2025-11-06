#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto& x : a) {
        scanf("%d", &x);
    }
    auto f = [&] (int b) -> long long {
        long long ans = 0;
        for (int i = 1, pre = a[0]; i < n; i++) {
            int cur = a[i];
            if ((i & 1) == b) {
                if (a[i] <= pre) {
                    cur = pre + 1;
                    ans += cur - a[i];
                }
            } else {
                if (a[i] >= pre) {
                    cur = pre - 1;
                    ans += a[i] - cur;
                }
            }
            pre = cur;
        }
        return ans;
    };
    printf("%lld\n", min(f(0), f(1)));
    return 0;
}

