/ 对于每个节点， 与之相连的边颜色不同
// 从 度数最大的点 dfs 染色
void solve(){
    int n; cin >> n;
    MAT g(n+1);

    VC du(n+1);
    For(i,1,n-1){
        int x,y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        du[x] ++, du[y] ++;
    }

    int mxid = max_element(all1(du)) - begin(du);    
    int mx = du[mxid];

    VC ans(n+1), co(n+1);
    co[mxid] = 1;

    function<void(int,int)> dfs = [&](int o, int fa){
        int c = 1;
        for(auto p:g[o]){
            if(p == fa) continue;
            while(co[o] == c || co[fa] == c) c ++;
            co[p] = c; c ++;
            dfs(p,o);
        }
    };

    dfs(mxid,0);
    cout << mx+1 << endl;
    For(i,1,n) cout << co[i] << ' ';
}
