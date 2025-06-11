#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, W, H, A[MAXN + 5][3], ans[MAXN + 5][2];

struct S {
    vector<int> vec;
    queue<int> q;
};
int who[MAXN + 5];
unordered_map<int, S> mp;

int main() {
    scanf("%d%d%d", &n, &W, &H);

    vector<int> ord;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) scanf("%d", &A[i][j]);
        if (A[i][0] == 1) ord.push_back(i), who[i] = i;
        else mp[A[i][1] - A[i][2]].vec.push_back(i);
    }
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return A[a][1] < A[b][1];
    });
    for (auto &p : mp) {
        auto &s = p.second;
        sort(s.vec.begin(), s.vec.end(), [&](int a, int b) {
            return A[a][1] < A[b][1];
        });
        for (int i = s.vec.size() - 1; i >= 0; i--) s.q.push(s.vec[i]);
    }

    for (int idx : ord) {
        int t = A[idx][1] - A[idx][2];
        if (!mp.count(t)) continue;
        auto &s = mp[t];
        s.q.push(idx);
        who[idx] = s.q.front(); s.q.pop();
    }

    for (int i = 1; i <= n; i++) if (who[i]) {
        ans[who[i]][0] = A[i][1];
        ans[who[i]][1] = H;
    }
    for (auto &p : mp) {
        auto &s = p.second;
        for (int i = s.vec.size() - 1; i >= 0; i--) {
            int t = s.q.front(); s.q.pop();
            ans[t][0] = W;
            ans[t][1] = A[s.vec[i]][1];
        }
    }
    for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}
