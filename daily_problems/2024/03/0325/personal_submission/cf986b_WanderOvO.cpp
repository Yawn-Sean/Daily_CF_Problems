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

const int N = 1e6 + 10;
const int M = 35;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 2e9;
const double eps = 1e-8;

/*
1 4 3 2 5: 3
1 4 2 3 5: 2
1 5 2 3 4: 3
4 5 2 3 1: 8
每次交换对逆序数的影响是多少？
*/

int T;
LL n, a[N], res, tmp[N];

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else {
            res += (mid - i + 1);
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (k = l; k <= r; k++) {
        a[k] = tmp[k];
    }
}

void merge_sort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, mid, r);
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    res = 0;
    merge_sort(1, n);
    // cout << res << endl;
    if (n % 2 == 0) {
        if (res % 2 == 0) {
            cout << "Petr\n";
        } else {
            cout << "Um_nik\n";
        }
    } else {
        if (res % 2 == 0) {
            cout << "Um_nik\n";
        } else {
            cout << "Petr\n";
        }
    }
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
    // cin >> T;
    prepare();
    while (T--) {
        init();
        solve();
    }
    
    return 0;
}