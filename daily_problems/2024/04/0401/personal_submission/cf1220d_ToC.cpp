/*
    https://codeforces.com/contest/1220/submission/254398308
    1、bipartite 等价于 没有奇数环
    2、任取x != y 属于B，由x和y构成的环：
        0 -> x -> 2x -> ...  -> lcm(x, y) -> ...  -> y -> 0
        长度为偶数，得到x和y的质因数分解中2的幂次相等
    3、按照S中每个数的质因数分解中2的幂次，对S进行划分
    4、最大的子集就是所有要保留的数
*/
int n, t;
LL b[N];
int cnt[64];
int p[N];
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++) {
        LL x = b[i];
        int tmp = 0;
        while (x % 2 == 0) {
            x /= 2;
            tmp++;
        }
        p[i] = tmp;
        cnt[tmp]++;
    }
    int maxv = 0,maxp = 0;
    for (int i = 0; i < 64; i++) {
        if (cnt[i] > maxv) {
            maxv = cnt[i];
            maxp = i;
        }    
    }

    cout << n - maxv << '\n';

    for (int i = 1; i <= n; i++) {
        if (p[i] != maxp)
            cout << b[i] << " ";
    }
    if (n > maxv) cout << '\n';

}
