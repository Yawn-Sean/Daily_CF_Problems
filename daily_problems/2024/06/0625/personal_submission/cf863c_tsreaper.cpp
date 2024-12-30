#include <bits/stdc++.h>
using namespace std;

bool win(int x, int y) {
    if (x == 2 && y == 1) return true;
    if (x == 1 && y == 0) return true;
    if (x == 0 && y == 2) return true;
    return false;
}

int main() {
    long long K;
    int x, y;
    scanf("%lld%d%d", &K, &x, &y); x--; y--;
    int A[3][3], B[3][3];
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) scanf("%d", &A[i][j]), A[i][j]--;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) scanf("%d", &B[i][j]), B[i][j]--;

    vector<array<int, 2>> vec;
    vec.push_back({0, 0});
    int cnt[2] = {0}, vis[3][3] = {0};
    for (int i = 1; !vis[x][y]; i++) {
        vis[x][y] = i;
        if (win(x, y)) vec.push_back({vec.back()[0] + 1, vec.back()[1]});
        else if (win(y, x)) vec.push_back({vec.back()[0], vec.back()[1] + 1});
        else vec.push_back(vec.back());
        int xx = A[x][y], yy = B[x][y];
        x = xx; y = yy;
    }

    int s = vis[x][y];
    if (K < s) printf("%d %d\n", vec[K][0], vec[K][1]);
    else {
        long long ans[2] = {vec[s - 1][0], vec[s - 1][1]};
        K -= s - 1;
        int r = (int) vec.size() - s;
        for (int i = 0; i < 2; i++) ans[i] += (K / r) * (vec.back()[i] - vec[s - 1][i]) + vec[s + K % r - 1][i] - vec[s - 1][i];
        printf("%lld %lld\n", ans[0], ans[1]);
    }
    return 0;
}
