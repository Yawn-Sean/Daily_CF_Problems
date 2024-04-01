#include <bits/stdc++.h>
#define MAXS ((int) 1e6)
using namespace std;

int n;
long long ans;
char s[MAXS + 10];

unordered_map<int, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int msk = 0;
        for (int j = 1; s[j]; j++) msk ^= 1 << (s[j] - 'a');
        for (int j = -1; j < 26; j++) {
            int goal = msk;
            if (j >= 0) goal ^= 1 << j;
            if (mp.count(goal)) ans += mp[goal];
        }
        mp[msk]++;
    }
    printf("%lld\n", ans);
    return 0;
}
