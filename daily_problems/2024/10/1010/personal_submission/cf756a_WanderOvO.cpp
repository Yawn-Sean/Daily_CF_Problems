/*
首先，从 i 连一条边到 p[i]，为了让每个肉能到每个位置，所以应该是一个环才行
如果不加限制，这个图应该是由若干个环组成，如何合并环？
假设一个环是 v1 -> v2 -> ... vk -> v1，另一个是 u1 -> u2 -> ... um -> u1
则把 vk 连到 u1，把 um 连到 v1，就可以了，需要改两个位置
假设一共有 cnt 个环，则需要改 cnt 个位置，每个环改一个位置
进一步，如何保证每个面都被烤到？
首先，如果 1 的个数是偶数个，则一定不能每个位置都烤到两面，所以得是奇数
奇数就一定行吗？好像是的
*/

int n, p[N], b[N];
vector<vector<int>> e(N);
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for (auto v : e[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        e[i].pb(p[i]);
    }
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == 1) {
            cnt1++;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            res++;
        }
    }
    if (res == 1) {
        res = 0;
    }
    res += (cnt1 % 2 == 0 ? 1 : 0);
    cout << res << "\n";
}    
