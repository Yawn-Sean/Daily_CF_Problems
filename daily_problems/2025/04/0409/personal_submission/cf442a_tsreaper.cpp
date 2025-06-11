#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, ans, A[MAXN + 5][2];
int cnt[5][5], flag[MAXN + 5];

bool check(int msk) {
    memset(flag, 0, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; i++) {
        if (msk >> A[i][0] & 1) flag[i] |= 1;
        if (msk >> (A[i][1] + 5) & 1) flag[i] |= 2;
    }

    int tmp[5][5];
    memcpy(tmp, cnt, sizeof(cnt));
    for (int i = 1; i <= n; i++) if (flag[i] == 3) tmp[A[i][0]][A[i][1]]--;

    vector<int> X[5], Y[5];
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
        if (tmp[i][j] > 0) X[i].push_back(j), Y[j].push_back(i);
    for (int i = 1; i <= n; i++) {
        if (flag[i] == 1) {
            if (X[A[i][0]].size() > 1) return false;
            tmp[A[i][0]][A[i][1]]--;
        } else if (flag[i] == 2) {
            if (Y[A[i][1]].size() > 1) return false;
            tmp[A[i][0]][A[i][1]]--;
        }
    }

    int rem = 0;
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (tmp[i][j] > 0) rem++;
    return rem <= 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[5]; scanf("%s", s);
        string COL = "RGBYW";
        for (int j = 0; j < 5; j++) if (s[0] == COL[j]) { A[i][0] = j; break; }
        A[i][1] = s[1] - '1';
        cnt[A[i][0]][A[i][1]]++;
    }

    ans = 1e9;
    for (int msk = 0; msk < (1 << 10); msk++) if (check(msk)) ans = min(ans, __builtin_popcount(msk));
    printf("%d\n", ans);
    return 0;
}
