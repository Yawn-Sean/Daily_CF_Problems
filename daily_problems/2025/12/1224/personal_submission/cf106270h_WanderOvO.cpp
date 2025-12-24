/*
题意其实就是让一个数组中的每个数
要么是 2 的幂，要么不包含 2 这个素因子
每次操作代价是 p，a[i] /= p, a[j] *= p
我们首先肯定要对每个数做素因数分解
对于每个数，我们需要枚举它变成 2 的幂，还是不包含 2 的数
变成 2 的幂，则要把其他的奇素因数挨个除掉，扔给别的数
变成不包含 2 的数，就要把所有的 2 挨个除掉
这两个代价需要算出来
我们还有个限制，需要至少有 a 个数是只有 2 的幂的，至少有 b 个数是奇数
怎么搞？我们直接无脑贪心，每个数按照代价最低的方案搞
最后个数不对怎么办？反悔
我们把两种代价作差排序，然后从小到大反悔就好了
*/

const int N = 1e6 + 10;

vector<int> min_prime;

void prepare() {
    min_prime.resize(N + 1, 0);
    vector<int> primes;
    primes.reserve(80000); 
    
    for (int i = 2; i <= N; i++) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            primes.push_back(i);
        }
        
        for (int p : primes) {
            if (p > min_prime[i] || i * p > N) {
                break;
            }
            min_prime[i * p] = p;
        }
    }
}
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> c(n + 1, 0);
    vector<LL> as, bs;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        LL cost0 = 0, cost1 = 0;
        while (c[i] % 2 == 0) {
            c[i] /= 2;
            cost1 += 2;
        }
        
        while (min_prime[c[i]] != 0) {
            int j = min_prime[c[i]];
            c[i] /= j;
            cost0 += j;
        }
        
        if (cost0 >= cost1) {
            res += cost1;
            bs.push_back(cost0 - cost1);
        } else {
            res += cost0;
            as.push_back(cost1 - cost0);
        }
    }
    
    // cout << as.size() << " " << bs.size() << "\n";
    
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    
    if (as.size() < a) {
        int cnt = a - as.size();
        for (int i = 0; i < cnt; i++) {
            res += bs[i];
        }
    }
    
    if (bs.size() < b) {
        int cnt = b - bs.size();
        for (int i = 0; i < cnt; i++) {
            res += as[i];
        }
    }
    
    cout << res << "\n";
}
