// https://codeforces.com/contest/1029/submission/258213523
PII a[MAXN];
PII L[MAXN], R[MAXN];
void sol()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i].ff >> a[i].ss;
    }
    int maxL = -1, minR = INF;
    L[0] = {0, 1e9};
    for (int i = 1; i <= n; i++) {
        maxL = max(maxL, a[i].ff);
        minR = min(minR, a[i].ss);
        L[i] = {maxL, minR};
    }
    maxL = -1, minR = INF;
    R[n + 1] = {0, 1e9};
    for (int i = n; i >= 1; i--) {
        maxL = max(maxL, a[i].ff);
        minR = min(minR, a[i].ss);
        R[i] = {maxL, minR};
    }
    int len = 0;
    for (int i = 1; i <= n; i++) {
        PII sl = L[i - 1], sr = R[i + 1];
        len = max(len, min(sl.ss, sr.ss) - max(sl.ff, sr.ff));
    }
    cout << len << '\n';
    
}
