int main()
{
    int n ;cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i ++) cin >> a[i];
    string s; cin >> s;
    int m = s.size();
    vector<int> memo(n, -1);
    auto dfs = [&](auto &&dfs, int i, int lim) ->int {
        if(i == -1) return 0;
        if(!lim && memo[i]!= -1) return memo[i];
        int res = 0;
        int up = lim ? s[i] - '0' : 1;
        for(int d = 0; d <= up; d ++) {
            int w = (d == 1) ? a[i] : 0;
            res = max(res, dfs(dfs, i - 1, lim && d == up) + w);
        } 
        if(!lim) memo[i] = res;
        return res;
    };
    cout << dfs(dfs, n - 1, true) << endl; 
    return 0;
}
