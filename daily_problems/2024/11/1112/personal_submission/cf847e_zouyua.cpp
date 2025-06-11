void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> posp, posa;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'P') posp.pb(i);
        else if(s[i] == '*') posa.pb(i);
    }
    int l = 0, r = n * 2 + 10;
    int sz = posa.size();
    auto check = [&](int mid) {
        int pt = 0;
        for(auto &p : posp) {
            if(abs(p - posa[pt]) > mid) continue;//不能直接return false
            int ldis = max(0, p - posa[pt]);
            int rdis = max(mid - 2 * ldis, (mid - ldis) / 2); //先左或者先右的最远距离
            int posr = p + rdis;
            while(pt < sz && posr >= posa[pt]) pt ++;
            //cout << ldis << ' ' << rdis << ' ' << posr <<' '<< pt<< endl;
            if(pt == sz) return true;
        }
        return false;
    };
    //check(2);
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}
