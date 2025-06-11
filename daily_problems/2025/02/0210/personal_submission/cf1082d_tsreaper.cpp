#include <bits/stdc++.h>
#define MAXN 500
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5];
vector<pii> ans;

void conn(int x, int y) {
    ans.push_back({x, y});
    A[x]--; A[y]--;
}

int main() {
    scanf("%d", &n);
    
    vector<int> X, Y;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] == 1) X.push_back(i);
        else Y.push_back(i);
    }

    if (Y.empty()) { printf("NO\n"); return 0; }

    int len = Y.size();
    for (int i = 1; i < Y.size(); i++) conn(Y[i - 1], Y[i]);
    if (X.size() > 0) len++, conn(X[0], Y[0]);
    if (X.size() > 1) len++, conn(X[1], Y.back());

    priority_queue<pii> pq;
    for (int y : Y) pq.push({A[y], y});
    for (int i = 2; i < X.size(); i++) {
        pii p = pq.top(); pq.pop();
        if (p.first == 0) { printf("NO\n"); return 0; }
        conn(X[i], p.second);
        pq.push({p.first - 1, p.second});
    }
    
    printf("YES %d\n%d\n", len - 1, ans.size());
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}
