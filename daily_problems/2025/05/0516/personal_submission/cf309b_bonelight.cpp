// 从尾到头 建立一个路径树 -- 一行可以走到的 即为一条路径
// dfs 遍历， 栈存储祖先，最远 r-1 代祖先gap 即为该点在最长单词数
void solve(){
    int n,r,c; cin >> n >> r >> c;
    MAT g(n+2, VC());
    
    vector<string> ss(n+1); For(i,1,n) cin >> ss[i];
    VC to(n+2), sum(n+2);
    int left = 1, right = 0, tot = 0;
    
    to[n+1] = n+1;
    For(i,1,n+1) sum[i] = sum[i-1] + (int)ss[i].size() + 1;
    Rof(i,n,1){
        to[i] = to[i+1];
        while(sum[to[i]-1]-sum[i-1]-1 > c) to[i] --;
        if(to[i] != i) g[to[i]].push_back(i);
    }

    // For(i,1,n+1) cout << to[i] << ' '; cout << endl;
    // For(i,1,n) {
    //     for(auto p:g[i]) cout << p << ' ';
    //     cout << endl;
    // }

    VC ans(n+2), stk;
    function<void(int)> dfs = [&](int o){
        stk.push_back(o);
        ans[o] = stk[max(0ll, (int)stk.size()-r-1)] - o;
        for(auto p:g[o]){
            dfs(p);
        }
        stk.pop_back();
    };

    For(i,1,n+1) if(to[i] == i) {
        stk.clear();
        dfs(i);
    }

    int st = max_element(all1(ans)) - begin(ans);
    while(r --){
        For(i,st,to[st]-1){
            cout << ss[i];
            if(i < to[st]-1) cout << ' ';
            else if(i == to[st]-1 && r != 0) cout << endl;
        }
        st = to[st];
    }
}
