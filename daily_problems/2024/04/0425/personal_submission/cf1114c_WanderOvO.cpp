/*
n! 素因数分解后包含 p 的多少次方？
n / p 为包含 p^1 的数的个数，n / p / p 为包含 p^2 的数的个数
n / p + n / p / p + ... 加起来之后就是 n! 中包含的 p 的次方数
n! 转化为 b 进制数后有多少个末尾 0 => 最大 b 的多少次方能整除 n!
对 b 做素因数分解，然后用 b 的每个 pi，去算 n! 包含多少次 pi，并除一下 ki

*/

int T;
LL n, b;
vector<LL> p, cnt;

void solve1() {
    cin >> n >> b;
    LL root = sqrt(b);
    for (int i = 2; i <= root; i++) {
        if (b % i == 0) {
            int c = 0;
            while (b % i == 0) {
                b /= i;
                c++;
            }
            p.pb(i);
            cnt.pb(c);
        }
    }
    if (b > 1) {
        p.pb(b);
        cnt.pb(1);
    }
    
    LL res = INF;
    for (int i = 0; i < p.size(); i++) {
        LL nn = n;
        LL c = 0;
        while (nn > 0) {
            c += nn / p[i];
            nn /= p[i];
        }
        res = min(res, c / cnt[i]);
    }
    cout << res;
}        