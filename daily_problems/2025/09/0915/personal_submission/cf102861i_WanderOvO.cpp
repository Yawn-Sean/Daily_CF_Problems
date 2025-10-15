/*
正常情况下，最小的集合其实就是叶子的数量，不可能比这个少
知道所有的叶子能推导出其他的
能不能不询问叶子，通过一些方法推导出叶子？可以的，比如某个点只有一个孩子，则问它之后它的孩子也知道了
注意到一个事情，假设 u 是若干个叶子 v 的直接父亲，则我们只能至多不询问其中一个 v
因为如果有两个 v 没被询问的话，即使询问了 u，也是不可能推导出这两个 v 的值的
等下，假如 u1 和 u2 分别是一些叶子的父亲，u1 中有一个叶子不问，u2 中也有一个叶子不问
u1 和 u2 有共同的父亲 fa，假如我们 u1 和 u2 也都不问，直接问 fa，会出现什么情况？
会导致只能知道没被问的两个叶子的和，不能确切的知道这两个没被问的叶子的值
其实这说明了一点，对于每个 u 点，考虑其所有的直接孩子 v，至多只能有一个 v 的值目前推导不出来
只有这样，才可能通过问 u 来确定 v
重新思考一下 dp
dp[u][0/1] 表示 u 中的值全都确定/仅有 1 个没确定的方案数
考虑转移，对于 dp[u][0]:
- v 们都确定了，则是 dp[v][0] 都乘起来，记为 prod，贡献到 dp[u][0] 中
- 某个 v 没确定，则为了完全确定 u 子树，必须询问 u。
  枚举 v，给 dp[u][0] 的贡献为 prod / dp[v][0] * dp[v][1]

对于 dp[u][1]:
- 假如所有的 v 都确定了，则 u 不可能确定不了
- 枚举到底哪个 v 子树中有恰好一个没确定的，则贡献为 prod / dp[v][0] * dp[v][1]

初始化叶子结点 u: dp[u][0] = 1, dp[u][1] = 1
会 WA，因为 0 的问题，所以最好用前后缀分解去算
*/

LL dp[N][2], n;
vector<vector<int>> e(N);
const int mod = 1e9 + 7;

LL qpow(LL a, LL b, LL mod) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return res % mod;
}

void dfs(int u) {
    if (e[u].size() == 0) {
        dp[u][0] = 1;
        dp[u][1] = 1;
        return;
    }

    vector<LL> pre_prod(e[u].size() + 2, 0), suf_prod(e[u].size() + 2, 0);
    int idx = 1;
    pre_prod[0] = 1;
    suf_prod[e[u].size() + 1] = 1;
    for (auto v : e[u]) {
        dfs(v);
        pre_prod[idx] = dp[v][0];
        suf_prod[idx] = dp[v][0];
        idx++;
    }

    for (int i = 1; i <= e[u].size(); i++) {
        pre_prod[i] *= pre_prod[i - 1];
        pre_prod[i] %= mod;
    }

    for (int i = e[u].size(); i > 0; i--) {
        suf_prod[i] *= suf_prod[i + 1];
        suf_prod[i] %= mod;
    }

    dp[u][0] = pre_prod[e[u].size()];
    dp[u][1] = 0;
    idx = 1;
    for (auto v : e[u]) {
        LL s = pre_prod[idx - 1] * suf_prod[idx + 1] % mod * dp[v][1] % mod;
        dp[u][0] += s;
        dp[u][0] %= mod;
        dp[u][1] += s;
        dp[u][1] %= mod;
        idx++;
    }
}

void meibao() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        e[p].push_back(i);
    }

    dfs(1);

    cout << dp[1][0] << "\n";
}   
