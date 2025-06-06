void solve(){
    int k;
    cin >> k;
    char _ = getchar();
    string s;
    getline(cin, s);
    int n = s.size();
    for (auto &ch : s){
        if (ch == ' ' || ch == '-') ch = '?';
    }

    auto chk = [&](int mid)->bool{
        int lst = -1, cut = -1, cnt = 0;
        for (int i = 0; i < n; ++ i){
            if (i-lst > mid){
                if (i-cut > mid) return false;
                lst = cut, cnt += 1;
            }
            if (s[i] == '?') cut = i;
        }
        return cnt < k;
    };
    int lo = 1, hi = n;
    while (lo < hi){
        int mid = (lo+hi) >> 1;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << "\n";
}

