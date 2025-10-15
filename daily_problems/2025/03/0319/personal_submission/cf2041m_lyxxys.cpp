void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }
    auto call = [&]()->i64{
        vector <int> B = A;
        sort(B.begin(), B.end());
        i64 ans = 1ll*n*n;
        priority_queue <int,vector<int>,greater<int>> pq;
        for (int i = 0, j = -1; i < n; ++ i){
            if (i > j) pq.push(A[i]);
            while (j+1 <= i && pq.top() == B[j+1]){
                j += 1;
                pq.pop();
            }
            while (j+1 > i && j+1 < n && A[j+1] == B[j+1]){
                j += 1;
            }
            fmin(ans, 1ll*(i+1)*(i+1) + 1ll*(n-j-1)*(n-j-1));
        }
        return ans;
    };

    i64 res = call();
    for (auto &x : A){
        x = -x;
    }
    reverse(A.begin(), A.end());
    fmin(res, call());

    cout << res << "\n";
}
