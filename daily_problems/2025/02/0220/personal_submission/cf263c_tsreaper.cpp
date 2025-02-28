#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n;
unordered_set<int> A[MAXN + 5];

vector<pii> goal;
vector<int> e[MAXN + 5];
bool vis[MAXN + 5];

bool check(vector<int> &ord) {
    vector<pii> actual;
    for (int i = 0; i < n; i++) {
        int x = ord[i];
        for (int j = 1; j <= 2; j++) {
            int y = ord[(i + j) % n];
            actual.push_back({min(x, y), max(x, y)});
        }
    }
    sort(actual.begin(), actual.end());
    return goal == actual;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n * 2; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        A[x].insert(y); A[y].insert(x);
        goal.push_back({x, y});
    }
    for (int i = 1; i <= n; i++) A[i].insert(i);
    sort(goal.begin(), goal.end());

    for (int i = 1; i <= n; i++) if (A[i].size() != 5) { printf("-1\n"); return 0; }

    if (n <= 6) {
        vector<int> ord;
        for (int i = 1; i <= n; i++) ord.push_back(i);
        while (true) {
            next_permutation(ord.begin(), ord.end());
            if (check(ord)) {
                for (int x : ord) printf("%d ", x);
                printf("\n");
                return 0;
            }
            bool same = true;
            for (int i = 0; i < n; i++) if (ord[i] != i + 1) { same = false; break; }
            if (same) break;
        }
        printf("-1\n");
    } else {
        for (int x = 1; x <= n; x++) for (int y : A[x]) if (x != y) {
            int cnt = 0;
            for (int z : A[x]) if (A[y].count(z)) cnt++;
            if (cnt == 4) e[x].push_back(y);
        }
        for (int i = 1; i <= n; i++) if (e[i].size() != 2) { printf("-1\n"); return 0; }

        vector<int> ord;
        for (int i = 1, last = 0; !vis[i]; ) {
            ord.push_back(i);
            vis[i] = true;
            for (int j : e[i]) if (j != last) {
                last = i;
                i = j;
                break;
            }
        }
        if (ord.size() != n || !check(ord)) { printf("-1\n"); return 0; }
        for (int x : ord) printf("%d ", x);
        printf("\n");
    }
    return 0;
}
