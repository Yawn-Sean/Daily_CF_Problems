#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
int a[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int n2 = n << 1;
        for (int i = 0; i < n2; i++) {
            scanf("%d", &a[(n + i) % n2]);
        }
        int ans = 0;
        map<int, int> diff_mp;
        diff_mp[0] = 0;
        int freq[2]{};
        for (int i = 1; i <= n2; i++) {
            freq[a[i - 1] - 1] += 1;
            auto it = diff_mp.find(freq[0] - freq[1]);
            if (it != diff_mp.end()) {
                if (i >= n) ans = max(ans, i - it->second);
            } else {
                if (i <= n) diff_mp[freq[0] - freq[1]] = i;
            }
        }
        printf("%d\n", n2 - ans);
    }
    return 0;
}

