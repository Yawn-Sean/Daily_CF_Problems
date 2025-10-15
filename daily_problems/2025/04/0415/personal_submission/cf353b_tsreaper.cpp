#include <bits/stdc++.h>
#define MAXN 100
#define MAXA 100
using namespace std;
typedef pair<int, int> pii;

int n, ans[MAXN * 2 + 5];
vector<int> vec[MAXA];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; i++) {
        int x; scanf("%d", &x);
        vec[x].push_back(i);
    }

    int cnt[2] = {0}, j = 0;
    for (int i = 10; i < MAXA; i++) if (vec[i].size() == 1) {
        ans[vec[i][0]] = j;
        cnt[j]++;
        j ^= 1;
    }
    for (int i = 10; i < MAXA; i++) if (vec[i].size() > 1) {
        for (int t = 0; t < vec[i].size(); t++) ans[vec[i][t]] = (j + t) % 2;
        cnt[0]++; cnt[1]++;
        if (vec[i].size() % 2) j ^= 1;
    }
    printf("%d\n", cnt[0] * cnt[1]);
    for (int i = 1; i <= n * 2; i++) printf("%d%c", ans[i] + 1, "\n "[i < n * 2]);
    return 0;
}
