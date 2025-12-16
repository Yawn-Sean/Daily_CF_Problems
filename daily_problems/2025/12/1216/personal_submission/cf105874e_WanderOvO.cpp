#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
先把询问按照莫队的规则离线了
然后，我们维护区间内目前每个素因子出现的次数，以及当前区间内的 rad 值
遇到新的素因子，或者某素因子个数变成 0 了，就更新 rad 值
把每个数所有素因数预处理出来
*/

const int MAXN = 5e5 + 10; 
const int MAXV = 2e5 + 10; 
const int MOD = 1e9 + 7;

int n, q;
int a[MAXN];
long long ans[MAXN];

vector<int> factors[MAXN]; 

int block_size;
struct Query {
    int l, r, id;
    
    bool operator<(const Query& other) const {
        int b_l = l / block_size;
        int b_r = other.l / block_size;
        if (b_l != b_r) return b_l < b_r;
        return (b_l % 2 == 0) ? (r < other.r) : (r > other.r);
    }
} queries[MAXN];

int cnt[MAXV]; 
long long cur_ans = 1;

int min_prime[MAXV]; 
long long inv[MAXV];

void sieve_and_inv() {
    inv[1] = 1;
    for (int i = 2; i < MAXV; ++i) {
        inv[i] = (long long)(MOD - MOD / i) * inv[MOD % i] % MOD;
    }

    for (int i = 2; i < MAXV; ++i) {
        if (min_prime[i] == 0) {
            for (int j = i; j < MAXV; j += i) {
                if (min_prime[j] == 0) min_prime[j] = i;
            }
        }
    }
}

void factorize(int idx, int val) {
    while (val > 1) {
        int p = min_prime[val];
        factors[idx].push_back(p);
        while (val % p == 0) val /= p;
    }
}

void add(int idx) {
    for (int p : factors[idx]) {
        if (cnt[p] == 0) {
            cur_ans = (cur_ans * p) % MOD;
        }
        cnt[p]++;
    }
}

void remove(int idx) {
    for (int p : factors[idx]) {
        cnt[p]--;
        if (cnt[p] == 0) {
            cur_ans = (cur_ans * inv[p]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve_and_inv();

    cin >> n >> q;
    
    block_size = max(1, (int)(n / sqrt(q)));

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        factorize(i, a[i]);
    }

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }

    sort(queries, queries + q);

    int L = 1, R = 0;
    for (int i = 0; i < q; ++i) {
        int ql = queries[i].l;
        int qr = queries[i].r;

        while (L > ql) add(--L);
        while (R < qr) add(++R);
        while (L < ql) remove(L++);
        while (R > qr) remove(R--);

        ans[queries[i].id] = cur_ans;
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}
