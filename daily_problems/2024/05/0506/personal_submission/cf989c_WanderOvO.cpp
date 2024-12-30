int a, b, c, d;
char s[55][55];

void solve1() {
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= 25; j++) {
            s[i][j] = 'A';
        }
    }
    for (int i = 1; i <= 25; i++) {
        for (int j = 26; j <= 50; j++) {
            s[i][j] = 'B';
        }
    }
    for (int i = 26; i <= 50; i++) {
        for (int j = 1; j <= 25; j++) {
            s[i][j] = 'C';
        }
    }
    for (int i = 26; i <= 50; i++) {
        for (int j = 26; j <= 50; j++) {
            s[i][j] = 'D';
        }
    }
    
    for (int i = 2; i <= 25; i += 2) {
        for (int j = 27; j <= 50; j += 2) {
            if (a > 1) {
                s[i][j] = 'A';
                a--;
            }
        }
    }
    
    for (int i = 27; i <= 50; i += 2) {
        for (int j = 2; j <= 25; j += 2) {
            if (b > 1) {
                s[i][j] = 'B';
                b--;
            }
        }
    }
    
    for (int i = 27; i <= 50; i += 2) {
        for (int j = 27; j <= 50; j += 2) {
            if (c > 1) {
                s[i][j] = 'C';
                c--;
            }
        }
    }
    
    for (int i = 2; i <= 25; i += 2) {
        for (int j = 2; j <= 25; j += 2) {
            if (d > 1) {
                s[i][j] = 'D';
                d--;
            }
        }
    }
    cout << "50 50\n";
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            cout << s[i][j];
        }
        cout << "\n";
    }
}   