/*
从 i 能移动到 j
- a[i] < a[j]
- a[i] | (i - j)
谁不能移动谁输
a[i] 互不相同
n 显然移动不到任何地方，1 可以移动到任何其他地方
如果 i 能移动到 j，则 j 不能移动到 i
1 <= a[i] <= n，所以能走的边有 O(nlogn) 条
有向图建出来，是 DAG，求 sg 函数即可
*/

int T;
int sg[N], n, a[N];
vector<vector<int>> e(N);

void dfs(int u) {
    if (sg[u] >= 0) {
        return;
    }

    unordered_set<int> s;
    for (auto &v : e[u]) {
        dfs(v);
        s.insert(sg[v]);
    }
    int val = 0;
    for ( ; s.count(val); val++);
    sg[u] = val;
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];    
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + a[i]; j <= n; j += a[i]) {
            if (a[i] < a[j]) {
                e[i].pb(j);
            }
        }
        for (int j = i - a[i]; j > 0; j -= a[i]) {
            if (a[i] < a[j]) {
                e[i].pb(j);
            }
        }
    }
    memset(sg, -1, sizeof sg);
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (sg[i] > 0) {
            cout << "A";
        } else {
            cout << "B";
        }
    }
}        