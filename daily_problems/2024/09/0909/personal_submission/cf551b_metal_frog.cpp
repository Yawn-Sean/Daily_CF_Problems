void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    vector<int> cntA(26), cntB(26), cntC(26);
    for (int i = 0; i < a.length(); i++) {
        cntA[a[i] - 'a']++;
    }
    for (int i = 0; i < b.length(); i++) {
        cntB[b[i] - 'a']++;
    }
    for (int i = 0; i < c.length(); i++) {
        cntC[c[i] - 'a']++;
    }
    int maxb = a.length();
    for (int c = 0; c < 26; c++) {
        if (cntB[c] != 0) {
            maxb = min(maxb, cntA[c] / cntB[c]);
        }
    }
    int maxTot = 0, maxc = 0;
    for (int i = 0; i <= maxb; i++) {
        vector<int> copyCntA = cntA;
        int cntSubC = a.length();
        for (int c = 0; c < 26; c++) {
            copyCntA[c] -= i * cntB[c];
            if (cntC[c] != 0) {
                cntSubC = min(cntSubC, copyCntA[c] / cntC[c]);
            }
        }
        if (i + cntSubC > maxTot) {
            maxTot = i + cntSubC;
            maxc = cntSubC;
        }
    }
    string ans;
    maxb = maxTot - maxc;
    for (int i = 0; i < maxb; i++) {
        ans += b;
        for (int c = 0; c < 26; c++) {
            cntA[c] -= cntB[c];
        }
    }
    for (int i = 0; i < maxc; i++) {
        ans += c;
        for (int c = 0; c < 26; c++) {
            cntA[c] -= cntC[c];
        }
    }
    for (int c = 0; c < 26; c++) {
        while (cntA[c] > 0) {
            ans += (c + 'a');
            cntA[c]--;
        }
    }
    cout << ans << "\n";
}
