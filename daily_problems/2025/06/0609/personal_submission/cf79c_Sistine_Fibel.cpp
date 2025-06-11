    string S;
    cin >> S;
    int n; cin >> n;
    vector<string> a(n);
    for(auto &c : a)
        cin >> c;
    int s = 0, t = 0, ans = 0, cnt = 0;
    while(s < S.length()){
        for(auto c : a){
            int tt = t - c.length() + 1;
            if(tt >= s && (S.substr(tt, c.size()) == c))
                s = max(s, tt + 1);
        }
        if(t - s + 1 > cnt)
            cnt = t - s + 1, ans = s;
        if(t != S.length() - 1)
            t ++;
        else
            s ++;
    }
    cout << cnt << ' ' << ans << endl;

// ٩ (◕‿◕�?) ۶
