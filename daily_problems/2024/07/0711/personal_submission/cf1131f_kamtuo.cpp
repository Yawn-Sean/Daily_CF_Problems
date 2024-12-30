int p[N], r[N], l[N];
int n;
int ne[N], fr[N];

int find(int x) {
    if (p[x] - x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) p[i] = r[i] = l[i] = i;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        int fu = find(u), fv = find(v);
        ne[r[fu]] = l[fv];
        fr[l[fv]] = r[fu];
        l[fv] = l[fu];
        p[fu] = fv;
    }
    for (int i = 1; i <= n; i ++) {
        if (fr[i] == 0) {
            while (i) {
                cout << i << ' ';
                i = ne[i];
            }
            break;
        }
    }
    return 0;
}
