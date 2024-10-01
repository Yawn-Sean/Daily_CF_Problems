/*
如果 color = ca[i] = cb[i]，则这个 color 赋什么权值贡献都是 0
可以连有向边 (ca[i], cb[i])，得到的图由一堆环组成，环上每条边的边权看成 abs(nums[i] - nums[j])
所有边权加起来就是要求的那个数
尽量一上一下可以重叠较多，可能求和之后更大一些，但不知道怎样能最大

羊神提示：
首先考虑在一个环上一大一小去排布值后怎么算总权值，发现就是 2 * (极大值的和 - 极小值的和)
我们看总共需要多少个极大值和极小值，假设各需要 cnt 个
直接取 [1, cnt] 为极小值，[n - cnt + 1, n] 为极大值，差就是 cnt * (n - cnt)，乘 2 就是总权值
*/

LL n, ca[N], cb[N];
vector<vector<int>> e(N);
bool vis[N];
int len;

void dfs(int u) {
    len++;
    vis[u] = true;
    for (int v : e[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> ca[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cb[i];
        e[ca[i]].pb(cb[i]);
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
    LL cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            len = 0;
            dfs(i);
            cnt += len / 2;
        }
    }
    cout << 2 * cnt * (n - cnt) << "\n";
}   
