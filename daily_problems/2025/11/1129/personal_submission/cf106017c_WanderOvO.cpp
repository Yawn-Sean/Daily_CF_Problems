#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
题目保证了被询问的位置是 [0, 10^8] 的整数
所以我们其实无需维护浮点数，只要整数取模保证不炸范围就好了
询问的时候，之前除的分母（乘的逆元）肯定被消掉了
所以，只需要维护区间加，区间乘就好了，我直接复制板子
*/

using ll = long long;

const int MAXN = 100005;
const ll MOD = 1e9 + 7;

int main() {
    vector<ll> a(MAXN, 0);
    
    SegmentTree st(a);
    
    int q;
    cin >> q;
    
    map<int, int> pos;
    const int mod = 1e9 + 7;
    int pt = 1;
    for (int i = 1; i <= q; i++) {
        int op, x, p, q, j;
        cin >> op;
        if (op == 1) {
            cin >> x;
            x = (x % mod + mod) % mod;
            st.range_add(pt, pt, x);
            pos[i] = pt;
            pt++;
        } else if (op == 2) {
            cin >> x;
            x = (x % mod + mod) % mod;
            st.range_add(1, pt - 1, x);
        } else if (op == 3) {
            cin >> p >> q;
            ll val = p * qpow(q, mod - 2, mod) % mod;
            val = (val % mod + mod) % mod;
            st.range_mul(1, pt - 1, val);          
        } else {
            cin >> j;
            cout << st.query_sum(pos[j], pos[j]) << "\n";
        }
    }
    
    return 0;
}
