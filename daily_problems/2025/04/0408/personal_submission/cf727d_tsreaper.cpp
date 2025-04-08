#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans[MAXN + 5];
int cnt[6];

vector<int> vec[6];

int gao(char *s, int len) {
    if (s[0] == 'S') return 0;
    else if (s[0] == 'M') return 1;
    else if (s[0] == 'L') return 2;
    else return len + 1;
}

int main() {
    for (int i = 0; i < 6; i++) scanf("%d", &cnt[i]);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[15]; scanf("%s", s);
        int pos;
        for (pos = 0; s[pos]; pos++) if (s[pos] == ',') break;
        int sz = gao(s, pos);
        if (s[pos] == ',') vec[sz].push_back(i);
        else {
            if (cnt[sz] == 0) { printf("NO\n"); return 0; }
            ans[i] = sz;
            cnt[sz]--;
        }
    }

    for (int i = 0; i < 6; i++) {
        if (i > 0) {
            while (cnt[i] > 0 && vec[i - 1].size() > 0) {
                ans[vec[i - 1].back()] = i;
                cnt[i]--;
                vec[i - 1].pop_back();
            }
        }
        while (cnt[i] > 0 && vec[i].size() > 0) {
            ans[vec[i].back()] = i;
            cnt[i]--;
            vec[i].pop_back();
        }
    }

    for (int i = 0; i < 5; i++) if (vec[i].size() > 0) { printf("NO\n"); return 0; }
    printf("YES\n");
    string tmp[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
    for (int i = 1; i <= n; i++) printf("%s\n", tmp[ans[i]].c_str());
    return 0;
}
