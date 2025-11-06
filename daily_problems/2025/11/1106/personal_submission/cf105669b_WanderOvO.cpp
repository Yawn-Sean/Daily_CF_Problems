/*
加减乘是平凡的，直接取模后运算即可
乘方有些说法，a ** b 的结果，我们可以对 a 取模，但是不能直接对 b 取模
b 的长度是 1e5，转化成二进制也是 1e6 以内长度
如果能做高精度进制转换，则后面只需要快速幂就可以求出来了
如果不做高精度进制转换还能做吗？
能否直接做一个基于 10 进制的快速幂呢？
*/

const int mod = 1e9 + 7;
string a, b, op;

LL qpow(LL a, string b, LL mod) {
    LL res = 1, base = a;
    int len = b.size();
    int idx = len - 1;
    while (idx >= 0) {
        if (b[idx] != '0') {
            for (int i = 0; i < b[idx] - '0'; i++) {
                res = res * base % mod;
            }
        }
        LL new_base = 1;
        for (int i = 1; i <= 10; i++) {
            new_base *= base;
            new_base %= mod;
        }
        base = new_base;
        idx--;
    }
    return res % mod;
}

LL to_value(string s) {
    LL res = 0;
    for (auto ch : s) {
        res = 10 * res + ch - '0';
        res %= mod;
    }
    return res;
}


void solve() {
    cin >> a >> op >> b;
    LL va = to_value(a), vb = to_value(b);
    if (op == "+") {
        cout << (va + vb) % mod << "\n";
    } else if (op == "-") {
        cout << ((va - vb) % mod + mod) % mod << "\n";
    } else if (op == "*") {
        cout << (va * vb) % mod << "\n";
    } else {
        cout << qpow(va, b, mod) << "\n";
    }
    
}
