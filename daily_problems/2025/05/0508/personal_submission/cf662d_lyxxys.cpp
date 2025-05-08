void solve(){
    auto fprint = [&](string s)->void{
        for (int i = s.size()-1; i >= 0; -- i){
            cout << s[i];
        }
        cout << "\n";
    };

    auto add_one = [&](string s, int i)->string{
        int n = s.size();
        while (i < n && s[i] == '9'){
            s[i] = '0';
            i += 1;
        }
        if (i < n){
            s[i] = char((int)s[i]+1);
        } else {
            s += "1";
        }

        return s;
    };
    auto call = [&](string suf)->void{
        string cur = "8891";
        for (int i = 0; i < suf.size(); ++ i){
            if (i+1 > cur.size()){
                cur += suf[i];
            } else if (suf[i] <= cur[i]){
                cur[i] = suf[i];
                cur = add_one(cur, i+1);
            } else {
                cur[i] = suf[i];
            }
            if (cur.back() == '0') cur += "1";
        }
        fprint(cur);
    };

    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        s = s.substr(4);
        reverse(s.begin(), s.end());
        call(s);
    }
}
