void solve(){
    auto f1 = [&](char ch)->bool{
        return isalpha(ch);
    };
    auto f2 = [&](char ch)->bool{
        return isdigit(ch);
    };
    auto f3 = [&](char ch)->bool{
        return ch == '_';
    };
    auto legal = [&](char ch)->bool{
        return f1(ch) || f2(ch) || f3(ch);
    };
    
    string s;
    cin >> s;
    int n = s.size();
    i64 res = 0;
    for (int i = 1; i < n-1; ++ i){
        if (s[i] == '@'){
            int mark = n-1, jug = -1;
            for (int j = i+1; j < n-1; ++ j){
                if (s[j] == '@'){
                    mark = j-1;
                    jug = 0;
                    break;
                } else if (s[j] == '.'){
                    mark = j;
                    jug = j > i+1;
                    break;
                }
            }
            if (jug == -1) break;
            if (!jug){
                i = mark;
                continue;
            }

            bool flg = 1;   // 检查中间是否都是字母和数字
            for (int j = i+1; j < mark; ++ j){
                if (!(f1(s[j]) || f2(s[j]))){
                    flg = 0;
                }
            }
            if (!flg){
                i = mark;
                continue;
            }

            i64 L = 0, R = 0, l = i, r = mark;
            while (l-1 >= 0 && legal(s[l-1])){
                l -= 1;
                L += f1(s[l]);
            }
            while (r+1 < n && f1(s[r+1])){
                r += 1;
                R += 1;
            }
            res += L*R;
            i = r;
        }
    }

    cout << res << "\n";
}
