void solve(){
    int n;
    cin >> n;
    cin.ignore();

    auto fout = [&](int x)->string{
        if (x < 0) return "errtype";
        string res = "void";
        for (int i = 0; i < x; ++ i){
            res += "*";
        }
        return res;
    };

    map <string, int> ref;
    ref["void"] = 0;
    auto ufix = [&](string buf)->int{
        string src;
        int cnt = 0;
        for (int i = 0; i < buf.size(); ++ i){
            if (islower(buf[i])){
                src += buf[i];
            } else if (buf[i] == '&'){
                cnt -= 1;
            } else if (buf[i] == '*'){
                cnt += 1;
            }
        }

        if (!ref.count(src)) return -1;
        if (ref[src] < 0) return -1;
        cnt += ref[src];
        return cnt < 0 ? -1 : cnt;
    };
    vector <string> ans;

    for (int i = 0; i < n; ++ i){
        vector <string> chs;
        string buf, line;

        getline(cin, line);
        stringstream sin(line);
        while (sin >> buf){
            chs.push_back(buf);
        }

        if (chs.size() == 2){
            string s = chs[1];
            ans.push_back( fout(ufix(s)) );
        } else {
            string buf = chs[1], tar = chs[2];
            assert(tar != "void");

            int cnt = ufix(buf);
            ref[tar] = cnt;
        }
    }

    for (auto &ch : ans){
        cout << ch << "\n";
    }
}
