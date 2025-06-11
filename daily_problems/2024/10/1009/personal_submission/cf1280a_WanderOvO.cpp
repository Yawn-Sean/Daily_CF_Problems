/*
23131
23131131131
23131131131
2313113113111311311131131
2313113113111311311131131
s 是不断变长的，上一轮的是这一轮的前缀
我们只关心前 x 个字符的具体值，后面只关心长度
所以当字符串长度 <= x 时，我们暴力拼接字符串
当字符串长度 > x 时，只统计长度
*/

void meibao() {
    int x;
    string s;
    cin >> x >> s;
    LL len = s.size();
    s = " " + s;
    bool too_long = false;
    int mod = MOD1;
    for (int i = 1; i <= x; i++) {
        int cnt = s[i] - '0';
        if (!too_long) {
            string t = s.substr(i + 1);
            for (int j = 0; j < cnt - 1; j++) {
                s += t;
                len += t.size();
            }
            if (len > x) {
                too_long = true;
            }
        } else {
            LL right_len = len - i;
            for (int j = 0; j < cnt - 1; j++) {
                len += right_len;
            }
            len = (len % mod + mod) % mod;
        }
    }
    cout << len << "\n";
}     
