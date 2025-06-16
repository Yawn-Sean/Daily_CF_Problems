// ٩ (◕‿◕�?) ۶
const int N = 2e5 + 5;
vector<int > v[N], ans;
int a[N], b[N];
int dfs(int x) {
    ans.push_back(x);
    a[x] = ans.size();
    int now = 0;
    for(int i = 0; i < v[x].size(); i ++)
        now += dfs(v[x][i]);
    return b[x] = now + 1;
}
void solve(){
    int n, q;
    cin >> n >> q;

    for(int i = 2; i <= n; i ++){
        int t; cin >> t;
        v[t].push_back(i);
    }

    dfs(1);

    for(int i = 1; i <= q; i ++){
        int x, y;
        cin >> x >> y;
        if(b[x] < y)
            cout << -1 << endl;
        else
            cout << ans[a[x] + y - 2] << endl;
    }
}

