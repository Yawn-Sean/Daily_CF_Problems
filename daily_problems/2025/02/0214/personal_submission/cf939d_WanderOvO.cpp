/*
购买一个咒语，将 c1 转化为 c2，或者 c2 转化为 c1，可以执行任意多次这个咒语
需要输出具体的方案
一共有 26 * 25 个咒语，每个咒语至多会购买一次
假设使用了咒语 (a, b) 和 (b, c)，则相当于 a b c 等价了
我们考虑看 s 和 t，如果 s[i] != t[i]，就认为 (s[i], t[i]) 应该等价才对
这样会建出一个图，每条边边权为 1，求最小生成树即可
*/

struct Edge {
    int u, v;
};

int n;
string s, t;
vector<Edge> e;
int fa[N];
void meibao() {
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            e.push_back({s[i] - 'a', t[i] - 'a'});
        }
    }

    for (int i = 0; i < 26; i++) {
        fa[i] = i;
    }
    vector<PII> res;
    for (int i = 0; i < e.size(); i++) {
        int u = e[i].u, v = e[i].v;
        if (!together(u, v)) {
            merge(u, v);
            res.push_back({u, v});
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        char c1 = res[i].x + 'a', c2 = res[i].y + 'a';
        cout << c1 << " " << c2 << "\n";
    }
}
