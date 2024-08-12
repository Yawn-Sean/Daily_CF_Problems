/*
删 1 到 n
显然第一个删 1
之后呢？
2 3 要删 2
2 3 4 要删 3
2 3 4 5 要删 3 5
1 2 3 4 5 6 7
1 1 1 1 2 2 6
只剩 3 个数时特殊处理
*/

int T;
int n;
vector<int> res;

void dfs(int n, int power) {
    if (n <= 3) {
        for (int i = 1; i < n; i++) {
            res.pb(power);
        }
        res.pb(n * power);
        return;
    }
    
    for (int i = 1; i <= n; i += 2) {
        res.pb(power);
    }
    n /= 2;
    dfs(n, power * 2);
}

void solve1() {
    cin >> n;
    dfs(n, 1);
    for (auto &val : res) {
        cout << val << " ";
    }
}    