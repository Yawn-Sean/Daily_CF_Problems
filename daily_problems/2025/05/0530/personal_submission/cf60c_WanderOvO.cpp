/*
gcd * lcm 就是两个数的乘积
每个数 <= 1e6，预处理最小素因子后做素因数分解是来得及的
从 lcm(a[i], a[j]) 中除掉 gcd(a[i], a[j])，剩下的所有素因子，每种要么只属于 a[i]，要么只属于 a[j]
想到一个可能的办法，随便先考虑某个 a[i]，这个 a[i] 的可能值的种类会不会比较有限呢？是否可以枚举之后暴力呢？
1e6 以内的数至多有 7 种不同素因子
考虑 lcm(a[i], a[j]) / gcd(a[i], a[j]) 中的那些素因子
对于每种素因子，要么全在 a[i] 这里，要么全在 a[j] 里
2^7 = 128 ，a[i] 至多有这么多种情况
然后用一遍 dfs 去求出其他所有的数，并验证是否合题意
128 * 5e3 * log(1e6) ，非常可以
由于不一定连通，所以每个连通分量都要搞一下，但复杂度不变
*/

struct Edge {
    LL v, g, l;
};

vector<vector<Edge>> e(M);
int n, m;
LL val[M];
bool vis[M], finished[M];

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

bool fill_val(int u) {
    vis[u] = true;
    bool res = true;
    for (auto &edge : e[u]) {
        LL v = edge.v, g = edge.g, l = edge.l;
        if (!vis[v]) {
            val[v] = g * l / val[u];
            if (gcd(val[v], val[u]) != g || lcm(val[v], val[u]) != l) {
                return false;
            }
            res &= fill_val(v);
        } else {
            if (gcd(val[v], val[u]) != g || lcm(val[v], val[u]) != l) {
                return false;
            }
        }
    }
    return res;
}

void finish(int u) {
    finished[u] = true;
    for (auto &edge : e[u]) {
        LL v = edge.v;
        if (!finished[v]) {
            finish(v);
        }
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        LL u, v, g, l;
        cin >> u >> v >> g >> l;
        e[u].push_back({v, g, l});
        e[v].push_back({u, g, l});
    }

    memset(finished, 0, sizeof finished);

    auto get_factors = [&] (LL val) -> vector<int> {
        vector<int> factors;
        LL root = sqrt(val);
        for (int i = 2; i <= root; i++) {
            if (val % i == 0) {
                LL prod = 1;
                while (val % i == 0) {
                    val /= i;
                    prod *= i;
                }
                factors.push_back(prod);
            }
        }
        if (val > 1) {
            factors.push_back(val);
        }
        return factors;
    };

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (!finished[i]) {
            if (e[i].size() == 0) {
                val[i] = 1;
                finished[i] = true;
            } else {
                if (e[i][0].l % e[i][0].g != 0) {
                    ok = false;
                    break;
                }
                LL independent = e[i][0].l / e[i][0].g;
                LL both = e[i][0].g;
                vector<int> ps = get_factors(independent);
                int cnt = ps.size();
                bool can_fill = false;
                for (int j = 0; j < (1 << cnt); j++) {
                    LL initial_val = both;
                    for (int k = 0; k < cnt; k++) {
                        if ((j >> k) & 1) {
                            initial_val *= ps[k];
                        }
                    }
                    val[i] = initial_val;
                    memset(vis, 0, sizeof vis);
                    can_fill |= fill_val(i);
                    if (can_fill) {
                        finish(i);
                        break;
                    }
                }
                if (!can_fill) {
                    ok = false;
                    break;
                }
            }
        }
    }

    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << val[i] << " ";
        }
    }
}
