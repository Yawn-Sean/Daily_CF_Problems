#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second 
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = N * 2, INF = 0x3f3f3f3f;

int a[N];
int h[N], e[M], ne[M], idx;
bool st1[N], st2[N];
int n, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u) {
    st1[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        if (i & 1) continue;
        int v = e[i];
        if (st1[v] || a[v] == 1) continue;
        dfs1(v);
    }
}

void dfs2(int u) {
    st2[u] = true;
    if (a[u] == 1) return;
    for (int i = h[u]; ~i; i = ne[i]) {
        if (!(i & 1)) continue;
        int v = e[i];
        if (st2[v]) continue;
        dfs2(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) dfs1(i);
        else if (a[i] == 2) dfs2(i);
    }

    for (int i = 1; i <= n; i++) {
        if (st1[i] && st2[i]) 
            cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}
