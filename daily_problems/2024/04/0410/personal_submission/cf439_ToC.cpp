
int n, t, m;
LL a[MAXN], b[MAXN];
LL prea[MAXN], preb[MAXN];
LL mina, maxb;

void sol()
{
    mina = INF, maxb = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
        mina = min(mina, a[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        maxb = max(maxb, b[i]);    
    }
    
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    for (int i = 1; i <= n; i++)
        prea[i] = prea[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
        preb[i] = preb[i - 1] + b[i];

    if (mina >= maxb) {
        cout << "0\n";
    } else {
        LL res = LNF;
        for (int i = 1; i <= n; i++) {
            LL t = a[i];
            int spa = lower_bound(a + 1, a + n + 1, t) - (a + 1) + 1;
            int spb = upper_bound(b + 1, b + m + 1, t) - (b + 1) + 1;
            res = min(res, 
                        (preb[m] - preb[spb - 1]) - (m - spb + 1) * t + (spa-1) * t - prea[spa - 1]);
        }
        for (int i = 1; i <= m; i++) {
            LL t = b[i];
            int spa = lower_bound(a + 1, a + n + 1, t) - (a + 1) + 1;
            int spb = upper_bound(b + 1, b + m + 1, t) - (b + 1) + 1;
            res = min(res, 
                        (preb[m] - preb[spb - 1]) - (m - spb + 1) * t + (spa-1) * t - prea[spa - 1]);
        }
        cout << res << '\n';
    }
    
}
