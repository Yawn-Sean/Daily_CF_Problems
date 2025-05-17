/*
最后一行选哪几个单词？显然是贪心最好，能放下就放，每行都应该是贪心放
我们要最大化的是选中的单词数
只要求出来了最后选哪个 [i, j]，可以很容易贪心构造出每行放啥
假设要求放 [i, j]，能否快速验证是否符合题意？
i 不变，j 增加的话，只是在行尾加或者增加新的行，好搞，但是 i 也增加的话就不好弄了
有一个想法，假如 j 是由 i - 1 转移过来的，就把 i - 1 和 j 放到同一个组里面去
但 j + 1 也可能由 i - 1 转移过来，而 j + 1 贪心不是因为 j 转移过来的
看起来能根据上一个在哪儿去构造一个森林，这样就是在树上找不超过 r 个点组成的链
每个点有一个权值(单词数)，要最大化链的权值
dfs 时维护栈中结点以及前缀和，即可求出最大的链权值
*/

vector<vector<int>> e(N);
int n, r, c, w[N];
string s[N];
bool vis[N];
int sum[N], cur_depth, max_cnt, start;
vector<int> stk;

void dfs(int u) {
    vis[u] = true;
    stk.push_back(u);
    sum[cur_depth] = sum[cur_depth - 1] + w[u];
    if (cur_depth < r) {
        if (sum[cur_depth] > max_cnt) {
            max_cnt = sum[cur_depth];
            start = stk[0];
        }
    } else {
        if (sum[cur_depth] - sum[cur_depth - r] > max_cnt) {
            max_cnt = sum[cur_depth] - sum[cur_depth - r];
            start = stk[cur_depth - r];
        }
    }
    for (auto v : e[u]) {
        cur_depth++;
        dfs(v);
        cur_depth--;
    }
    stk.pop_back();
}

void meibao() {
    cin >> n >> r >> c;
    int idx = 1;
    while (cin >> s[idx]) {
        idx++;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << s[i] << "\n";
    // }
    int l = 1, len = 0;
    for (int r = 1; r <= n; r++) {
        if (len == 0) {
            len += s[r].size();
        } else {
            len += s[r].size() + 1;
        }
        while (l <= r && len > c) {
            if (l == r) {
                len -= s[l].size();
            } else {
                len -= s[l].size() + 1;
            }
            l++;
        }
        w[r] = r - l + 1;
        if (len != 0 && l - 1 != 0) {
            // len = 0 说明只要包含 s[r] 就一定会爆长度
            e[l - 1].push_back(r);
            // cout << l - 1 << " " << r << "\n";
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << w[i] << " ";
    // }

    max_cnt = -1;
    start = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cur_depth = 1;
            dfs(i);
        }
    }
    // cout << max_cnt << "\n";
    if (max_cnt > 0 && start > 0) {
        // cout << start << "\n";
        int tmp = start;
        start++;
        len = 0;
        for (int i = tmp; i > 0; i--) {
            if (len + s[i].size() + (len != 0) > c) {
                break;
            } else {
                len += s[i].size() + (len != 0);
                start = i;
            }
        }

        int line_cnt = 0, cur_line_len = 0;
        for (int i = start; i <= n; i++) {
            if (cur_line_len + s[i].size() + (cur_line_len != 0) <= c) {
                if (cur_line_len != 0) {
                    cout << " ";
                }
                cout << s[i];
                cur_line_len += s[i].size() + (cur_line_len != 0);
            } else {
                cout << "\n";
                line_cnt++;
                cur_line_len = 0;
                if (line_cnt >= r || s[i].size() > c) {
                    break;
                } else {
                    cur_line_len = s[i].size();
                    cout << s[i];
                }
            }
        }
    }
}   
