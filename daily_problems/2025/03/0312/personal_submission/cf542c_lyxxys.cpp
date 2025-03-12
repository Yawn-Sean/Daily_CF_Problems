void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
        x -= 1;
    }

    i64 ans = 1;
    int mi = 0; 
    for (int i = 0; i < n; ++ i){
        vector <int> vis(n, -1);
        vis[i] = 0;

        int cur = i;
        while (true){
            int j = A[cur];
            if (vis[j] != -1){
                i64 sz = vis[cur]-vis[j]+1;
                ans = ans / __gcd(sz, ans) * sz;
                fmax(mi, vis[j]);
                break;
            }
            vis[j] = vis[cur]+1;
            cur = j;
        }
    }

    i64 res = ans;
    while (res < mi) res += ans;

    cout << res << "\n";
}
