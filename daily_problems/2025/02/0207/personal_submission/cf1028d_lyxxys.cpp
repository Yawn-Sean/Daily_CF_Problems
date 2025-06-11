void solve(){
    auto error = [&]()->void{
        cout << 0 << "\n";
    };
    const int mod = 1e9+7;

    int n;
    cin >> n;
    vector<array<int,2>> As(n);
    vector <int> A;
    for (int i = 0; i < n; ++ i){
        string cur;
        cin >> cur >> As[i][1];
        if (cur == "ACCEPT"){
            As[i][0] = 1;
            A.push_back(i);
        }
    }
    assert(As[0][0] == 0);

    int j = 0;
    auto move = [&]()->void{
        ++ j;
        while (As[j][0] == 1) ++ j;
    };
    priority_queue <int> pq1;  // 下面的大根堆
    priority_queue <int,vector<int>,greater<int>> pq2;  // 上面的小根堆

    i64 res = 1;  // 对顶堆统计贡献
    for (auto &id : A){
        int x = As[id][1];

        if (!pq1.empty()){
            if (x < pq1.top()) return error();
        }
        if (!pq2.empty()){
            if (x > pq2.top()) return error();
        }
        
        bool jg = 0;
        while (j < id){  // 划分成小于 x 的集合 和 大于 x 的 集合
            int y = As[j][1];
            if (y < x) pq1.push(y);
            else if (y > x) pq2.push(y);
            if (y == x) jg = 1;
            move();
        }

        if (jg) res = res*2 % mod;  //如果 x 有选择划分到两个集合的机会的话统计贡献

        if (!pq1.empty()){
            if (pq1.top() == x) pq1.pop();
        }
        if (!pq2.empty()){
            if (pq2.top() == x) pq2.pop();
        }
    }

    int v = 1;
    for (int i = A.size() ? A.back()+1 : 0; i < n; ++ i){
        int x = As[i][1];
        if (!pq1.empty() && x < pq1.top()) continue;
        if (!pq2.empty() && x > pq2.top()) continue;
        v += 1;
    }

    cout << v*res%mod << "\n";
}
