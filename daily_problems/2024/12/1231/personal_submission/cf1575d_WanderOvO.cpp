/*
8 位数，一共有 1e8 个数，能被 25 整除的数有 4e6 个
暴力计算出这 4e6 个数，然后挨个和 s 比对即可
*/
 
string s;
 
bool check(int res) {
    string t = to_string(res);
    if (s.size() != t.size()) {
        return false;
    }
    int len = s.size();
    int x = -1;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i]) && isdigit(t[i]) && s[i] != t[i]) {
            return false;
        }
        if (s[i] == 'X') {
            if (x == -1) {
                x = t[i] - '0';
            } else {
                if (x != t[i] - '0') {
                    return false;
                }
            }
        }
    }
    return true;
}
 
void meibao() {
    cin >> s;
    int mx = 1e8;
    int res = 0;
    for (int i = 0; i < mx; i += 25) {
        if (check(i)) {
            res++;
        }
    }
    cout << res << "\n";
}   
