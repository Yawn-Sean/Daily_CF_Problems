int n, m;
string s;

void solve() {
    cin >> n >> m;
    cin >> s;
    int segs = 0, sum = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '.') {
            int j = i;
            while (j < n and s[j] == '.') j ++;
            sum += (j - i);
            segs += 1;
            i = j - 1;
        }
    }
    
    while (m --) {
        int x;
        string ss;
        cin >> x >> ss;
        x -= 1;
        if (ss[0] != '.' and s[x] != '.') {
            cout << sum - segs << endl;
            continue;
        }
        if (ss[0] == '.' and s[x] == '.') {
            cout << sum - segs << endl;
            continue;
        }
        if (ss[0] == '.') {
            if ((x - 1 >= 0 and s[x - 1] == '.') and (x + 1 < n and s[x + 1] == '.')) {
                segs -= 1;
                sum += 1;
            }
            else if ((x - 1 >= 0 and s[x - 1] == '.')) {
                sum += 1;
            }
            else if (x + 1 < n and s[x + 1] == '.') {
                sum += 1;
            }
            else {
                segs += 1;
                sum += 1;
            }
        }
        else {
            if ((x - 1 >= 0 and s[x - 1] == '.') and (x + 1 < n and s[x + 1] == '.')) {
                segs += 1;
                sum -= 1;
            }
            else if ((x - 1 >= 0 and s[x - 1] == '.')) {
                sum -= 1;
            }
            else if (x + 1 < n and s[x + 1] == '.') {
                sum -= 1;
            }
            else {
                segs -= 1;
                sum -= 1;
            }
        }
        s[x] = ss[0];
        cout << sum - segs << endl;
    }
}