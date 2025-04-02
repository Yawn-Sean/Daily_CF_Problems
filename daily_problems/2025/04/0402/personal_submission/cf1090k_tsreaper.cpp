#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXS ((int) 1e6)
using namespace std;

int n;
char s1[MAXS + 5], s2[MAXS + 5];

int main() {
    scanf("%d", &n);
    
    unordered_map<int, unordered_map<string, vector<int>>> mp;
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", s1 + 1, s2 + 1);
        int msk = 0;
        for (int j = 1; s2[j]; j++) msk |= 1 << (s2[j] - 'a');
        int r = strlen(s1 + 1);
        for (; r > 0 && (msk >> (s1[r] - 'a') & 1); r--);
        string key;
        for (int j = 1; j <= r; j++) key.push_back(s1[j]);
        mp[msk][key].push_back(i);
    }
    
    int ans = 0;
    for (auto &p : mp) ans += p.second.size();
    printf("%d\n", ans);
    for (auto &p1 : mp) for (auto &p2 : p1.second) {
        auto &vec = p2.second;
        printf("%d", vec.size());
        for (int x : vec) printf(" %d", x);
        printf("\n");
    }
    return 0;
}
