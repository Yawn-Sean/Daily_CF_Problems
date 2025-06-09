void solve(){
    auto tout = [&](string s)->void{
        cout << s << "\n";
    };
    auto fout = [&](string u, int x)->void{
        cout << u << "E" << x << "\n";
    };

    string s;
    cin >> s;

    if (s.find('.') != string::npos){
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
    }

    int point = -1, n = s.size(), start = n, rbound;
    for (int i = n-1; i >= 0; -- i){
        if (s[i] == '.'){
            point = i;
        }
        if (s[i] != '0' && s[i] != '.'){
            start = i;
        }
    }
    for (int i = 0; i < n; ++ i){
        if (s[i] != '0' && s[i] != '.'){
            rbound = i;
        }
    }

    bool jug = 0;
    for (int i = start+1; i < n; ++ i){
        if (s[i] != '0' && s[i] != '.'){
            jug = 1;
        }
    }
    if (point == -1){
        string tar;
        tar += s[start];
        if (n-start-1 == 0) return tout(tar);

        if (jug){
            tar += ".";
            for (int i = start+1; i <= rbound; ++ i){
                tar += s[i];
            }
        }
        fout(tar, n-start-1);
    } else {
        string tar;
        tar += s[start];
        if (jug){
            tar += ".";
            for (int i = start+1; i <= rbound; ++ i){
                if (i == point) continue;
                tar += s[i];
            }
        }
        
        if (point-start-1 == 0) return tout(tar);

        fout(tar, point > start ? point-start-1 : point-start);
    }
}
