/*
什么时候会出现拐点？零点处会增加/减少直线，可能会导致变化，否则不会变化
对于没零点的直线，不会带来影响
每个零点都一定会带来影响吗？是的
可能有一些直线的零点重合了，需要放到一起考虑
*/

int n;
set<PII> st;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k, b;
        cin >> k >> b;
        // kx + b = 0 => x = -b / k
        if (k != 0) {
            int g = gcd(k, b);
            if (g != 0) {
                k /= g;
                b /= g;
            }
            b = -b;
            if (b < 0) {
                b = -b;
                k = -k;
            }
            if (b == 0) {
                st.insert({0, 0});
            } else {
                st.insert({b, k});
            }
        }
    }
    cout << st.size() << "\n";
}     
