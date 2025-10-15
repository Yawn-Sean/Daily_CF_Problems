**提示 1：** 其实一个点的数值确定，和他相邻的点就确定了。

**提示 2：** 一个点的初始选择如何呢？

首先，提示 1，为什么呢？

一个经典的恒等式！ $\mathrm{gcd}(x,y)\times\mathrm{lcm}(x,y)=xy$

所以，只需知道 $x$ ，以及 $\mathrm{gcd}(x,y),\mathrm{lcm}(x,y)$ ，就可以知道 $y$ 了。一个连通块内只需要一个点确定了，其他数值也就都确定了！

而确定完后，该连通块内各个最大公约数、最小公倍数的条件也就能检查一遍了。

于是考虑枚举连通块内其中一个点的数值。怎么枚举呢？

- 如果没有边，直接赋值 $1$ 。

- 如果有边，取一条边，该点的数值一定是最小公倍数的因子。因子个数并不会特别多。

时间复杂度为 $\mathcal{O}(md(M)\log M)$ ，其中 $d(M)$ 表示不超过 $M$ 的数中因子最多的数的因子个数。当然这个并跑不满。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n, m = MII()

    us = [0] * m
    vs = [0] * m
    gcds = [0] * m
    lcms = [0] * m

    path = [[] for _ in range(n)]

    for i in range(m):
        us[i], vs[i], gcds[i], lcms[i] = MII()
        us[i] -= 1
        vs[i] -= 1
        path[us[i]].append(i)
        path[vs[i]].append(i)

    ans = [-1] * n

    for i in range(n):
        if ans[i] == -1:
            if len(path[i]) == 0:
                ans[i] = 1
                continue
            
            total_flg = False
            
            cur_l = 0
            for eid in path[i]:
                cur_l = math.gcd(cur_l, lcms[eid])
            
            for x in range(1, 1001):
                if cur_l % x == 0:
                    f = x
                    flg = True
                    
                    ans[i] = f
                    
                    stk = [i]
                    tmp = [i]
                    
                    
                    while stk:
                        u = stk.pop()
                        
                        for eid in path[u]:
                            v = us[eid] + vs[eid] - u
                            g = gcds[eid]
                            l = lcms[eid]
                            
                            if ans[u] == 0: break
                            
                            if ans[v] == -1:
                                ans[v] = g * l // ans[u]
                                tmp.append(v)
                                stk.append(v)
                            
                            if math.gcd(ans[u], ans[v]) != g or ans[u] * ans[v] != g * l:
                                flg = False
                                break
                    
                    if flg:
                        total_flg = True
                        break
                    
                    for u in tmp:
                        ans[u] = -1
                    
                    f = cur_l // x
                    flg = True
                    
                    ans[i] = f
                    
                    stk = [i]
                    tmp = [i]
                    
                    while stk:
                        u = stk.pop()
                        
                        for eid in path[u]:
                            v = us[eid] + vs[eid] - u
                            g = gcds[eid]
                            l = lcms[eid]
                            
                            if ans[u] == 0: break
                            
                            if ans[v] == -1:
                                ans[v] = g * l // ans[u]
                                tmp.append(v)
                                stk.append(v)

                            if math.gcd(ans[u], ans[v]) != g or ans[u] * ans[v] != g * l:
                                flg = False
                                break
                    
                    if flg:
                        total_flg = True
                        break
                    
                    for u in tmp:
                        ans[u] = -1

            if not total_flg:
                exit(print('NO'))

    print('YES')
    print(*ans)
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 3>>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v, g, l;
        cin >> u >> v >> g >> l;

        u --, v --;
        path[u].push_back({v, g, l});
        path[v].push_back({u, g, l});
    }

    vector<long long> ans(n, -1);

    for (int i = 0; i < n; i ++) {
        if (ans[i] == -1) {
            if (path[i].size() == 0) {
                ans[i] = 1;
                continue;
            }

            bool total_flg = false;

            int cur_l = 0;
            for (auto &[u, g, l]: path[i])
                cur_l = gcd(cur_l, l);
            
            for (int x = 1; x <= 1000; x ++) {
                if (cur_l % x == 0) {
                    bool flg;

                    auto dfs = [&] (auto &self, int u) -> void {
                        if (!ans[u]) {
                            flg = false;
                            return;
                        }

                        for (auto &[v, g, l]: path[u]) {
                            if (ans[v] == -1) {
                                ans[v] = 1ll * g * l / ans[u];
                                self(self, v);
                            }
                            if (1ll * ans[v] * ans[u] != 1ll * g * l || gcd(ans[u], ans[v]) != g) {
                                flg = false;
                                break;
                            }
                        }
                    };

                    auto reset = [&] (auto &self, int u) -> void {
                        ans[u] = -1;
                        for (auto &[v, g, l]: path[u]) {
                            if (ans[v] != -1) {
                                ans[v] = -1;
                                self(self, v);
                            }
                        }
                    };

                    flg = true;
                    ans[i] = x;
                    dfs(dfs, i);

                    if (flg) {
                        total_flg = true;
                        break;
                    }

                    reset(reset, i);

                    flg = true;
                    ans[i] = cur_l / x;
                    dfs(dfs, i);

                    if (flg) {
                        total_flg = true;
                        break;
                    }

                    reset(reset, i);
                }
            }
            if (!total_flg) return cout << "NO", 0;
        }
    }
    cout << "YES\n";
    for (auto &x: ans) cout << x << ' ';

    return 0;
}
```