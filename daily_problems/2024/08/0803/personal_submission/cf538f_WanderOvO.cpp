/*
我们考虑每个结点给哪些 k 贡献了答案
首先要看结点 v 可能是哪些点的儿子，并且是这个点的儿子多少次
考虑整除分块，对于 k = 1...n - 1，v 应该至多有根号个不同的父亲 u
每个 u 作为父亲的次数似乎可以分块求出来
v in [k * (u - 1) + 2, k * (u - 1) + k + 1]
对于 v，在 k 叉树中，其父亲的下标 u 是多少？
k * (u - 1) + 2 <= v <= k * u + 1
u >= (v - 1) / k, u <= (v - 2) / k + 1
*/

int T; 

void solve1() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> res(n + 1, 0);
    for (int v = 2; v <= n; v++) {
        /*
        枚举儿子结点 v，看哪些点 u 可以是父亲结点
        以及在哪些 k 时，u 是 v 的父亲
        */
        if (v == 2) {
            if (a[1] > a[2]) {
                res[1]++;
                res[n]--;
            }
            continue;
        }
        for (int l = 1, r; l <= v - 2; l = r + 1) {
            int u = (v - 2) / l + 1;
            r = (v - 2) / ((v - 2) / l);
            if (a[u] > a[v]) {
                res[l]++;
                res[r + 1]--;
            }
        }
        if (a[1] > a[v]) {
            res[v - 1]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        res[i] += res[i - 1];
    }
    for (int i = 1; i < n; i++) {
        cout << res[i] << " ";
    }
} 
