// https://codeforces.com/contest/1151/submission/266785407
PLL arr[MAXN];
LL diff[MAXN];
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }   
    LL v1 = 0, v2 = 0;
    for (int i = 1; i <= n; i++) {
        v2 += (arr[i].second * n - arr[i].first);
        diff[i] = arr[i].first - arr[i].second;
    }
    sort(diff + 1, diff + n + 1);
    for (int i = 1; i <= n; i++) 
        v1 += (diff[i] * (n + 1 - i));
    cout << v1 + v2 << '\n';
}
