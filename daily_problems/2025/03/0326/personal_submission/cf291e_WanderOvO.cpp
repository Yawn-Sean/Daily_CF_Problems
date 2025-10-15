/*
羊神提示：只需要考虑 DFS 边新增字符时，后缀是否匹配上了即可，因为新匹配上的只可能是后缀
因此，只要每加入一个字符，就算一个哈希即可，回溯之后重算哈希
*/

struct Edge {
    int v;
    string s;
};

LL h[N], n, p[N];
vector<vector<Edge>> e(N);
string t;
LL target_hash = 0;
int mod = MOD1;
LL res = 0;

LL get(int l, int r) {
    return ((h[r] - h[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}

void dfs(int u, int st) {
    for (auto &edge : e[u]) {
        for (int i = 0; i < edge.s.size(); i++) {
            h[st + i] = P * h[st + i - 1] + edge.s[i];
            h[st + i] %= mod;
            int r = st + i, l = r - t.size() + 1;
            if (l > 0) {
                if (get(l, r) == target_hash) {
                    res++;
                }
            }
        }
        dfs(edge.v, st + edge.s.size());
    }
}

void meibao() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        Edge edge;
        int fa;
        cin >> fa >> edge.s;
        edge.v = i;
        e[fa].push_back(edge);
    }

    cin >> t;
    for (int i = 0; i < t.size(); i++) {
        target_hash = P * target_hash + t[i];
        target_hash %= mod;
    }

    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = P * p[i - 1] % mod;
    }

    dfs(1, 1);

    cout << res << "\n";
}   
