/*
只看最长的那两个字符串，先一个取前缀一个取后缀，看看行不行
不行的话就反过来，这样一定行
*/

int n;
string s[N];
int group[N];
 
void meibao() {
    cin >> n;
    for (int i = 1; i <= 2 * n - 2; i++) {
        cin >> s[i];
    }

    string pre, suf;
    for (int i = 1; i <= 2 * n - 2; i++) {
        if (s[i].size() == n - 1) {
            if (pre == "") {
                pre = s[i];
            } else {
                suf = s[i];
            }
        }
    }

    memset(group, 0, sizeof group);
    bool finished = true;
    for (int len = 1; len < n; len++) {
        bool ok = false;
        for (int i = 1; i <= 2 * n - 2; i++) {
            if (pre.substr(0, len) == s[i] && !group[i]) {
                group[i] = 1;
                ok = true;
                break;
            }
        }
        if (!ok) {
            finished = false;
            break;
        }
    }
    for (int len = 1; len < n; len++) {
        bool ok = false;
        for (int i = 1; i <= 2 * n - 2; i++) {
            if (suf.substr(n - len - 1, len) == s[i] && !group[i]) {
                group[i] = 2;
                ok = true;
                break;
            }
        }
        if (!ok) {
            finished = false;
            break;
        }
    }

    if (finished) {
        for (int i = 1; i <= 2 * n - 2; i++) {
            cout << (group[i] == 1 ? "P" : "S");
        }
        return;
    }

    memset(group, 0, sizeof group);
    finished = true;
    swap(pre, suf);
    for (int len = 1; len < n; len++) {
        bool ok = false;
        for (int i = 1; i <= 2 * n - 2; i++) {
            if (pre.substr(0, len) == s[i] && !group[i]) {
                group[i] = 1;
                ok = true;
                break;
            }
        }
        if (!ok) {
            finished = false;
            break;
        }
    }
    for (int len = 1; len < n; len++) {
        bool ok = false;
        for (int i = 1; i <= 2 * n - 2; i++) {
            if (suf.substr(n - len - 1, len) == s[i] && !group[i]) {
                group[i] = 2;
                ok = true;
                break;
            }
        }
        if (!ok) {
            finished = false;
            break;
        }
    }

    assert(finished);
    for (int i = 1; i <= 2 * n - 2; i++) {
        cout << (group[i] == 1 ? "P" : "S");
    }
}   
