// https://codeforces.com/contest/1025/submission/261313334
string s;
void sol()
{
    cin >> s;
    string t {s};
    s += t;
    s += t;
    int n = s.size();
    int l = 0, r = 0;
    int res = 1;
    while (r < n) {
        while (r < n) {
            if ((r - l) % 2 == 0 && s[r] == s[l]) {
                r++;
            } else if ((r - l) % 2 == 1 && s[r] != s[l]){
                r++;
            } else break;
        }
        res = max(res, r - l);
        l = r;
    }
    cout << (res > t.size() ? t.size() : res) << "\n";
}
