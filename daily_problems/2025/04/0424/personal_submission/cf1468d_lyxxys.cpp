void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int d1 = abs(b-a) - 1;
    int d2 = a < b ? b-1 : n-b;

    vector <int> A(m);
    for (auto &x : A){
        cin >> x;
    }
    sort(A.begin(), A.end());

    auto chk = [&](int mid)->bool{
        for (int i = mid-1, cur = 1; i >= 0; -- i, cur += 1){
            if (A[i]+cur > d2){
                return false;
            }
        }
        return true;
    };

    int lo = 0, hi = min(m, d1);
    while (lo < hi){
        int mid = (lo+hi+1) >> 1;
        if (chk(mid)) lo = mid;
        else hi = mid-1;
    }

    cout << lo << "\n";
}
