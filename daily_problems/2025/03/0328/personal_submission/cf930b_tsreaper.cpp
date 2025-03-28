#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n;
char s[MAXN + 5];
double ans;

int main() {
    scanf("%s", s); n = strlen(s);
    vector<int> vec[26];
    for (int i = 0; i < n; i++) vec[s[i] - 'a'].push_back(i);

    for (int c = 0; c < 26; c++) {
        if (vec[c].empty()) continue;
        if (vec[c].size() == 1) { ans += 1.0 / n; continue; }
        int mx = 0;
        for (int i = 1; i < n; i++) {
            int cnt[26] = {0};
            for (int x : vec[c]) cnt[s[(x + i) % n] - 'a']++;
            int t = 0;
            for (int j = 0; j < 26; j++) if (cnt[j] == 1) t++;
            mx = max(mx, t);
        }
        ans += 1.0 * mx / n;
    }

    printf("%.12f\n", ans);
    return 0;
}
