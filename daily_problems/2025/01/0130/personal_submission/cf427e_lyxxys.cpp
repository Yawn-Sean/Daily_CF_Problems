
void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    auto chk = [&](int mid)->i64{
        i64 res = 0;
        int l = 0, r = n-1;
        while (l < mid){
            res += 2ll*(A[mid]-A[l]);
            l += m;
        }
        while (r > mid){
            res += 2ll*(A[r]-A[mid]);
            r -= m;
        }
        return res;
    };


    int lo = 0, hi = n-1;
    while (lo < hi){
        int m = (hi-lo)/3;
        int m1 = lo+m, m2 = hi-m;
        if (chk(m1) < chk(m2)) hi = m2-1;
        else lo = m1+1;
    }

    i64 res = chk(lo);
    cout << res << "\n";
}
