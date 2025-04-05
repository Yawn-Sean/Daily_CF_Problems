#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
bool A[8][8];
vector<pii> ans;

int dis[8][8];
pii from[8][8];
short dir[8][2] = {1, 2, 2, 1, -1, -2, -2, -1, 1, -2, -2, 1, -1, 2, 2, -1};

void bfs(int SI, int SJ) {
    memset(dis, -1, sizeof(dis));
    queue<pii> q;
    q.push({SI, SJ}); dis[SI][SJ] = 0;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int i = p.first, j = p.second;
        for (int k = 0; k < 8; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii < 0 || jj < 0 || ii >= 8 || jj >= 8 || dis[ii][jj] >= 0) continue;
            q.push({ii, jj});
            dis[ii][jj] = dis[i][j] + 1;
            from[ii][jj] = {i, j};
        }
    }
}

void gao(int SI, int SJ, int FI, int FJ) {
    bfs(SI, SJ);

    vector<pii> vec;
    for (int i = FI, j = FJ; i != SI || j != SJ; ) {
        vec.push_back({i, j});
        int ii = from[i][j].first, jj = from[i][j].second;
        i = ii; j = jj;
    }
    vec.push_back({SI, SJ});
    reverse(vec.begin(), vec.end());

    for (int i = 1, j = 1; i < vec.size(); i++) if (!A[vec[i].first][vec[i].second]) {
        for (int k = i; k >= j; k--) {
            int ia = vec[k - 1].first, ja = vec[k - 1].second;
            int ib = vec[k].first, jb = vec[k].second;
            swap(A[ia][ja], A[ib][jb]);
            ans.push_back({ia * 8 + ja, ib * 8 + jb});
        }
        j = i + 1;
    }
}

void gao(int FI, int FJ) {
    for (int i = 7; i >= 0; i--) for (int j = 7; j >= 0; j--)
    if (A[i][j]) { gao(i, j, FI, FJ); return; }
}

void print(int idx) {
    printf("%c%d", idx % 8 + 'a', idx / 8 + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[5]; scanf("%s", s);
        A[s[1] - '1'][s[0] - 'a'] = true;
    }

    for (int idx = 0; idx < n; idx++) {
        int i = idx / 8, j = idx % 8;
        if (!A[i][j]) gao(i, j);
    }

    printf("%d\n", ans.size());
    for (pii p : ans) {
        print(p.first);
        printf("-");
        print(p.second);
        printf("\n");
    }
    return 0;
}
