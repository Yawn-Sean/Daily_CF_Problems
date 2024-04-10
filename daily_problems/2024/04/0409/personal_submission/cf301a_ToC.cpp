//https://codeforces.com/contest/301/submission/255896362
int n, t, m;
int N[210], P[210];

void sol()
{
    cin >> n;

    int neg = 0, pos = 0, x;
    for (int i = 1; i < 2 * n; i++) {
        cin >> x;
        if (x < 0) N[neg++] = x;
        else P[pos++] = x;
    }
    sort(P, P + pos);
    sort(N, N + neg, [&](int a, int b) {
        return a > b;
    });
    int res = 0;
    for (int i = 0; i < pos; i++)
        res += P[i];
    if (neg % 2 == 0 || n % 2 == 1) {
        for (int i = 0; i < neg; i++)
            res += -N[i];
    } else {  
        neg--;
        while (neg >= 1) {
            N[neg] = -N[neg];
            res += N[neg];
            neg--;
        }
        if (pos > 0 && abs(N[0]) > P[0])
            res += (abs(N[0]) - 2 * P[0]);
        else res += N[0];
    }
    
    cout << res << '\n';
}
