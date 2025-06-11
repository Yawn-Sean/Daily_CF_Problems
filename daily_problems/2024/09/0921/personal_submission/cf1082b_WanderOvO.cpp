int T;
string s;
int n;
 
void solve1() {
    cin >> n >> s;
    vector<PII> segs;
    int res = 0;
    int gcnt = 0;
    for (int i = 0; i < n; i++) {
        int len = 0;
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                len++;
            } else {
                break;
            }
        }
        if (s[i] == 'G') {
            res = max(res, len);
            gcnt++;
            segs.pb({0, len});
        } else {
            segs.pb({1, len});
        }
        i += len - 1;
    }
    for (int i = 0; i < segs.size(); i++) {
        if (segs[i].x == 0 && i >= 2) {
            if (segs[i - 1].y == 1) {
                res = max(res, segs[i].y + segs[i - 2].y);
                if (gcnt > 2) {
                    res = max(res, segs[i].y + segs[i - 2].y + 1);
                }
            }
        }
        if (segs[i].x == 0 && gcnt > 1) {
            res = max(res, segs[i].y + 1);
        }
    }
    cout << res << "\n";
}              
