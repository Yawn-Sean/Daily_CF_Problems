// https://codeforces.com/contest/1153/submission/265527396
char s[MAXN];
void sol()
{   
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    if (n % 2 == 1 || s[1] == ')' || s[n] == '(') {
        cout << ":(\n";
        return;
    } else if (n == 2) {
        cout << "()\n";
        return ;
    } else if (n == 4) {
        if (s[2] == ')' || s[3] == '(') {
            cout << ":(\n";
            return;
        }
        cout << "(())\n";
        return ;
    }
    // n > 4
    if (s[2] == ')' || s[n - 1] == '(') {
        cout << ":(\n";
        return;
    }
    s[1] = '(', s[n] = ')';
    s[2] = '(', s[n - 1] = ')';

    int cnt = 0, tot = (n - 2) / 2;
    for (int i = 2; i < n - 1; i++) {
        if (s[i] == '(')
            cnt++;
    }

    if (cnt > tot) {
        cout << ":(\n";
        return;
    } else {
        int i = 3;
        while (i < n - 1 && cnt < tot) {
            if (s[i] == '?') {
                s[i] = '(';
                cnt++;
            }
            i++;
        }
        if (cnt < tot) {
            cout << ":(\n";
            return;
        }
        cnt = 0;
        for (int i = 2; i <= n - 1; i++) {
            if (s[i] == '(') { 
                cnt++;
            } else {
                s[i] = ')';
                cnt--;
            }
            if (cnt < 0) {
                cout << ":(\n";
                return;
            }
        }
        if (cnt == 0) {
            for (int i = 1; i <= n; i++)
                cout << s[i];
            cout << '\n';
        } else {
            cout << ":(\n";
            return;
        }
    }
}
