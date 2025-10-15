#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    int64 k;
    scanf("%d%I64d", &n, &k);
    map<int, int> freq;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        freq[x] += 1;
    }
    for (auto&[x, cnt] : freq) {
        if (k <= 1LL * cnt * n) {
            int y;
            for (auto&[x1, cnt1] : freq) {
                if (k <= 1LL * cnt1 * cnt) {
                    y = x1;
                    break;
                } else {
                    k -= 1LL * cnt1 * cnt;
                }
            }
            printf("%d %d\n", x, y);
            break;
        } else {
            k -= 1LL * cnt * n;
        }
    }
    return 0;
}

