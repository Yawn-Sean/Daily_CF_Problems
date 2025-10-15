int n;
string s;

void solve() {
    cin >> s;
    vector<int> a;
    reverse(all(s));
    for (auto c : s) {
        a.push_back(c - '0');
    }
    
    for (int i = 0; i < sz(a); i ++) {
        if (a[i] > 7) {
            a[i] = 0;
            if (i + 1 < sz(a)) a[i + 1] += 1;
            else a.push_back(1);
        }
    }
    reverse(all(a));
    
    n = sz(a);
    int c4 = (n + 1) / 2, c7 = c4;
    
    if (n & 1) {
        cout << string(c4, '4') << string(c7, '7') << endl;
        return;
    }
    
    string res;
    for (int i = 0; i < n; i ++) {
        int u = a[i];
        if (u < 4) {
            if (c4 > 0) res.push_back('4'), c4 --;
            else res.push_back('7'), c7 --;
            res += string(c4, '4');
            res += string(c7, '7');
            cout << res << endl;
            return;
        }
        else if (u == 4) {
            if (c4 > 0) {
                res.push_back('4'), c4 --;
                continue;
            }
            res.push_back('7'), c7 --;
            res += string(c7, '7');
            break;
        }
        if (c7 <= 0) {
            if (c4 == (n + 1) / 2) {
                cout << string(n / 2 + 1, '4') << string(n / 2 + 1, '7') << endl;
                return;
            }
            // 把前面的4换成7即可
            while (sz(res) and (res.back() != '4' or c7 == 0)) {
                if (res.back() == '4') c4 ++;
                else c7 ++;
                res.pop_back();
            }
            if (sz(res) and res.back() == '4' and c7 > 0) {
                c4 += 1;
                c7 -= 1;
                res.back() = '7';
                cout << res << string(c4, '4') << string(c7, '7') << endl;
                return;
            }
            cout << string(n / 2 + 1, '4') << string(n / 2 + 1, '7') << endl;
            return;
        }
        if (u < 7) {
            res.push_back('7'), c7 --;
            res += string(c4, '4');
            res += string(c7, '7');
            break;
        }
        else {
            res.push_back('7'), c7 --;
        }
    }
    
    cout << res << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}
