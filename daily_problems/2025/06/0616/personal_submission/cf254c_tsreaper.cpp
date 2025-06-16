#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans;
char s1[MAXN + 5], s2[MAXN + 5];

int cnt1[26], cnt2[26];
vector<int> pos[26];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%s%s", s1 + 1, s2 + 1); n = strlen(s1 + 1);
    for (int i = 1; i <= n; i++) {
        cnt1[s1[i] - 'A']++;
        cnt2[s2[i] - 'A']++;
        pos[s1[i] - 'A'].push_back(i);
    }

    vector<int> vec;
    for (int i = 0; i < 26; i++) {
        if (cnt1[i] > cnt2[i]) ans += cnt1[i] - cnt2[i];
        else for (int j = 1; j <= cnt2[i] - cnt1[i]; j++) vec.push_back(i);
    }
    reverse(vec.begin(), vec.end());
    printf("%d\n", ans);

    for (int i = 1; i <= n; i++) {
        int c = s1[i] - 'A';
        if (c >= 0 && c < 26 && cnt1[c] > cnt2[c]) {
            if (vec.back() < c) {
                cnt1[c]--;
                s1[i] = vec.back() + 'A';
                vec.pop_back();
            } else {
                int rem = cnt1[c] - cnt2[c];
                for (int j = 1; j <= rem; j++) s1[pos[c][pos[c].size() - j]] = '!';
                cnt1[c] = cnt2[c];
            }
        }
        if (s1[i] == '!') s1[i] = vec.back() + 'A', vec.pop_back();
    }
    printf("%s\n", s1 + 1);
    return 0;
}
