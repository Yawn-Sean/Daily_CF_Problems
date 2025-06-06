void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }
 
    vector<array<int,2>> nodes(1), cnts(1);
    array<int,2> node = {0, 0};
    int tot = 0;
    const int rt = 0;
    auto open = [&]()->int{ 
        nodes.push_back(node);
        cnts.push_back(node);
        return ++ tot;
    };
 
    auto insert = [&](int x)->void{
        int u = rt;
        for (int i = 29; i >= 0; -- i){
            int c = x>>i & 1;
            if (!nodes[u][c]){
                nodes[u][c] = open();
            }
            cnts[u][c] += 1;
            u = nodes[u][c];
        }
    };
    auto find = [&](int x)->int{
        int u = rt, res = 0;
        for (int i = 29; i >= 0; -- i){
            int c = x>>i & 1;
            if (cnts[u][c]){
                u = nodes[u][c];
                if (c) res |= 1 << i;
            } else {
                u = nodes[u][!c];
                if (!c) res |= 1 << i;
            }
        }
        return res;
    };
    auto deles = [&](int x)->void{
        int u = rt;
        for (int i = 29; i >= 0; -- i){
            int c = x>>i & 1;
            assert(cnts[u][c] > 0);
            cnts[u][c] -= 1;
            u = nodes[u][c];
        }
    };
 
    for (int i = 0,x; i < n; ++ i){
        cin >> x;
        insert(x);
    }
    vector <int> ans;
    for (auto &x : A){
        int y = find(x);
        deles(y);
        ans.push_back(x^y);
    }
    print(ans);
}
