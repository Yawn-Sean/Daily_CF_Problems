/*
m 很小时，我们都可以暴力枚举数字，然后真的把所有的重算一遍，看看是否会更大
位数 m 为 1000，所以不可能直接枚举值了
可以把输入建模成一个有向图，每个点有两条入边
? 是一个入度为 0 的点
位运算各个位是独立的，所以可以单独去算每个位的贡献怎样能最小/最大
考虑从高位到低位枚举应该填什么，然后只看当前这一位的贡献即可，总共只需要算 2000 种情况
每次计算时，需要遍历整个图，每个结点的计算时间是 O(1) 的，需要算 2000 轮，复杂度可以接受
*/

int n, m, sum, d[N], buf_d[N];
vector<vector<int>> e(N);
vector<vector<int>> from(N);
string vals[N], ops[N];
int bit_vals[N];
map<string, int> name_to_id;

void calc(int bit_id, int bit_value) {
    for (int i = 1; i <= n; i++) {
        bit_vals[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (vals[i].size() != 0) {
            bit_vals[i] = vals[i][bit_id] - '0';
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        buf_d[i] = d[i];
    }
    bit_vals[n + 1] = bit_value;

    queue<int> q;
    for (int i = 1; i <= n + 1; i++) {
        if (d[i] == 0) {
            q.push(i);
        }
    }

    auto get_value = [&] (int i, int j, string &op) -> int {
        if (op == "AND") {
            return (bit_vals[i] & bit_vals[j]);
        } else if (op == "OR") {
            return (bit_vals[i] | bit_vals[j]);
        } else {
            return (bit_vals[i] ^ bit_vals[j]);
        }
    };

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (from[u].size() != 0) {
            bit_vals[u] = get_value(from[u][0], from[u][1], ops[u]);
        }
        if (u != n + 1) {
            sum += bit_vals[u];
        }
        for (auto v : e[u]) {
            d[v]--;
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        d[i] = buf_d[i];
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string name, op, val1, val2;
        cin >> name >> op >> val1;
        name_to_id[name] = i;
        if (isdigit(val1[0])) {
            vals[i] = val1;
        } else {
            cin >> op;
            cin >> val2;
            ops[i] = op;
            d[i] = 2;
            if (val1 == "?") {
                e[n + 1].push_back(i);
                from[i].push_back(n + 1);
            } else {
                e[name_to_id[val1]].push_back(i);
                from[i].push_back(name_to_id[val1]);
            }

            if (val2 == "?") {
                e[n + 1].push_back(i);
                from[i].push_back(n + 1);
            } else {
                e[name_to_id[val2]].push_back(i);
                from[i].push_back(name_to_id[val2]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        sum = 0;
        calc(i, 0);
        int res1 = sum;
        sum = 0;
        calc(i, 1);
        int res2 = sum;
        if (res1 <= res2) {
            cout << "0";
        } else {
            cout << "1";
        }
    }

    cout << "\n";

    for (int i = 0; i < m; i++) {
        sum = 0;
        calc(i, 0);
        int res1 = sum;
        sum = 0;
        calc(i, 1);
        int res2 = sum;
        if (res1 >= res2) {
            cout << "0";
        } else {
            cout << "1";
        }
    }
}
