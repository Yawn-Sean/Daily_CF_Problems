#include <bits/stdc++.h>
    
#define x first
#define y second
#define ls (k << 1)
#define rs (k << 1 | 1)
#define mp make_pair
#define pb push_back
    
using namespace std; 

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, char> PIC;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<LL, LL> PLL;
typedef pair<PII, PII> PIIII;

const int N = 10010;
const int M = 15;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 1e9;
const double eps = 1e-8;

/*
约数函数 d(n) 的求法
1. 枚举 sqrt(n) 以内的约数，复杂度 O(sqrt(n)) 求出 d(n)
2. 枚举约数 i，枚举倍数 j，f[i * j]++，复杂度 O(nlogn) 求出所有的 d(1...n)
3. 筛素数的过程中求积性函数，复杂度 O(nloglogn)
4. 对 n 素因数分解，乘法原理求个数

题目保证 d(n) <= 1e9，但 d(n) = 1e9 起码是 (1e9)!，是个非常大的数
对于 n 和 x，我们维护 n 的素因子及其次数以及 x 的素因子及其次数，理论上就可以计算 d(n * x) 了
现在问是否存在 gcd(a, n * x) = 1，使得 d(n * x * a) = n * x
由于 gcd(a, n * x) = 1，所以计算 d(n * x * a) 中引入的都是新的素因子
我们不关心 a 具体是多少，只关心 a 引入了多少个新的素因子，以及素因子的次数，互素也不需要考虑
d(n * x) = (cnt1 + 1) * (cnt2 + 1) * ... * (cntk + 1)
d(n * x * a) = (cnt1 + 1) * ... * (cntk + 1) * (new_cnt1 + 1) * ... * (new_cntm + 1) = n * x
所以 d(n * x) 得是 n * x 的约数
所以我们计算出 d(n * x) 之后，再对 d(n * x) 做一次素因数分解，判断素因子能否完全被 n * x 的包括
*/

int T;
LL n, x, q;
map<LL, LL> n_factors;

void getFactors(LL val, map<LL, LL> &factors) {
    LL rt = sqrt(val);
    for (int i = 2; i <= rt; i++) {
        if (val % i == 0) {
            factors[i] = 0;
            while (val % i == 0) {
                val /= i;
                factors[i]++;
            }
        }
    }
    if (val > 1) {
        factors[val] = 1;
    }
}

void mergeFactors(map<LL, LL> &f1, map<LL, LL> &f2) {
    for (auto &it : f2) {
        LL p = it.x, cnt = it.y;
        if (f1.count(p)) {
            f1[p] += cnt;
        } else {
            f1[p] = cnt;
        }
    }
}

LL getCnt(map<LL, LL> &f) {
    LL res = 1;
    for (auto &it : f) {
        res *= (it.y + 1);
    }
    return res;
}

bool belong(map<LL, LL> &f1, map<LL, LL> &f2) {
    bool res = true;
    for (auto &it : f2) {
        LL val = it.x, cnt = it.y;
        if (!f1.count(val)) {
            return false;
        }
        if (f1[val] < cnt) {
            return false;
        }
    }
    return true;
}

void solve1() {
    cin >> n >> q;
    n_factors.clear();
    getFactors(n, n_factors);
    int op;
    while (q--) {
        cin >> op;
        if (op == 2) {
            n_factors.clear();
            getFactors(n, n_factors);
        } else {
            cin >> x;
            map<LL, LL> x_factors;
            getFactors(x, x_factors);
            mergeFactors(n_factors, x_factors);
            LL cnt = getCnt(n_factors);
            map<LL, LL> cnt_factors;
            getFactors(cnt, cnt_factors);
            if (belong(n_factors, cnt_factors)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    cout << "\n";
}

void solve2() {
    
}
    
void prepare() {
    
}

void init() {

}
    
void solve() {
    solve1();
}
    
int main() {
    #ifdef LOCAL_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    T = 1;
    cin >> T;
    prepare();
    while (T--) {
        init();
        solve();
    }
    
    return 0;
}