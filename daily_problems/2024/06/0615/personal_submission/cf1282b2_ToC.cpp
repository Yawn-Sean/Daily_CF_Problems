// https://codeforces.com/contest/1282/submission/266200989
int n, m, k, p;
int a[MAXN];
int sum[MAXN];
void sol()
{
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    memset(sum, 0, sizeof sum);
    for (int i = 1; i < k; i++) sum[i] = sum[i - 1] + a[i];
    int q = n / k;
    for (int i = 1; i <= q; i++) sum[i * k] = sum[(i - 1) * k] + a[i * k];
    for (int i = k + 1; i <= n; i++) {
        if (sum[i] == 0) {
            sum[i] = a[i] + sum[i - k];
        }
    }  
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (sum[i] <= p && i > res)
            res = i; 
    }
    cout << res << '\n';
}  
