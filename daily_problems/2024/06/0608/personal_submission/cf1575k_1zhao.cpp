typedef long long LL;
const int mod = 1e9 + 7;

int qmi(LL a, LL k, int p)  // 求a^k mod p
{
    LL res = 1 % p;
    while (k)
    {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

void solve() {
    int n, m, r, c, k;
    cin >> n >> m >> k >> r >> c;
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    
    long long nm = (long long) n * m, rc = (long long) r * c;

    if(ax==bx && ay==by) cout << qmi(k, nm, mod) << endl;
    else cout << qmi(k, nm - rc, mod) << endl;
}
