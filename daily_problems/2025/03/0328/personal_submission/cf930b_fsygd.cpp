#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int l, ans, delta, total;
int a[5010];
char s[5010];
int cnt[26];
vector<vector<int>> lists(26, vector<int>());

int main() {
    scanf("%s", s);
    l = strlen(s);
    for (int i = 0; i < l; ++i) {
        a[i] = s[i] - 'a';
        lists[a[i]].emplace_back(i);
    }
    for (int i = 0; i < 26; ++i) {
        delta = 0;
        for (int j = 1; j < l; ++j) {
            memset(cnt, 0, sizeof(cnt));
            for (const auto& x: lists[i]) ++cnt[a[(x + j) % l]];
            total = 0;
            for (int k = 0; k < 26; ++k) if (cnt[k] == 1) ++total;
            delta = max(delta, total);
        }
        ans += delta;
    }
    printf("%.15Lf\n", (long double)ans / l);
    return 0;
}