void solve(){
    const int inf = 1e9;

    int n, m, lst = 0;
    cin >> n >> m;
    vector <int> cols(n), hori;
    priority_queue <int,vector<int>,greater<int>> pq;
    for (auto &x : cols){
        cin >> x;
    }
    for (int i = 0,x1,x2,y; i < m; ++ i){
        cin >> x1 >> x2 >> y;
        if (x1 == 1){
            if (x2 == inf) lst += 1;
            else pq.push(x2);
        }
    }
    sort(cols.begin(), cols.end());

    int res = n;
    for (int i = 0; i < n; ++ i){
        while (!pq.empty() && pq.top() < cols[i]){
            pq.pop();
        }
        // cout << pq.size() << "\n";
        fmin(res, i+(int)pq.size());
    }

    cout << res+lst << "\n";
}
