void solve(){
    int n;
    cin >> n;
    vector <int> cnts1(n), cnts2(n), ids(n);
    iota(ids.begin(), ids.end(), 0);
    for (int i = 0,a,f; i < n; ++ i){
        cin >> a >> f;
        a -= 1;
        cnts1[a] += 1;
        if (f) cnts2[a] += 1;
    }

    sort(ids.begin(), ids.end(), [&](int u, int v){
        return cnts1[u] > cnts1[v];
    });

    i64 res = 0, ans = 0;
    priority_queue <int> pq;
    int j = 0;
    for (int i = n; i > 0; -- i){
        while (j < n && cnts1[ids[j]] >= i){
            pq.push(cnts2[ids[j]]);
            j += 1;
        }

        if (pq.size()){
            res += i;
            ans += min(i, pq.top());
            pq.pop();
        }
    }
    
    cout << res << " " << ans << "\n";
}
