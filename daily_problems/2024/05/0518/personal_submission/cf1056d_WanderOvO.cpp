/*
答案肯定是单调的
统计一下每个结点有多少个叶子
假如只涂 cnt 种颜色，那么叶子结点个数 <= cnt 的肯定是可以的
*/

int T;
vector<int> e[N];
int n, leaf_cnt[N];

void solve1() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int fa;
        cin >> fa;
        e[i].pb(fa);
        e[fa].pb(i);
    }
    dfs(1, 0);
    sort(leaf_cnt + 1, leaf_cnt + n + 1);
    for (int k = 1; k <= n; k++) {
        cout << leaf_cnt[k] << " "; 
    }
}    