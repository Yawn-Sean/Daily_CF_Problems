// d[i][j] 第 i 点，得到 j 车 的时间
// dijk 跑 d[i][j] 拓展图
// d[n][1~n] 取 min 得到结果
void solve(){
    int n,m; cin >> n >> m;
    MATii g(n+1, VCii());

    For(i,1,m) {
        int x,y,w; cin >> x >> y >> w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
    
    VC bike(n+1);
    For(i,1,n) cin >> bike[i];

    MAT d(n+1, VC(n+1, INF)), vis(n+1, VC(n+1));

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    auto dijk = [&](int st){
        d[st][st] = 0;
        pq.emplace(0,st,st);
        while(pq.size()){
            auto [l,o,b] = pq.top(); pq.pop();
            if(vis[o][b]) continue;
            vis[o][b] = 1;

            for(auto pp:g[o]){
                int p = pp.x, w = pp.y;
                int nxd = l + w*bike[b];
                int nxb = (bike[b]<bike[p]? b:p);
                if(d[p][nxb] > nxd){
                    d[p][nxb] = nxd;
                    pq.emplace(nxd, p, nxb);
                }
            }
        }
    };

    dijk(1);
    cout << *min_element(all(d[n])) << endl;
}
