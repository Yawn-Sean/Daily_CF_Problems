/*
a ^ c + b ^ c = lcm(a, c) + lcm(b, c)
右边是 c 的倍数，左边应该也是才对
lcm(a, c) + lcm(b, c) = a * c / gcd(a, c) + b * c / gcd(b, c)
a ^ c + b ^ c = (a / gcd(a, c) + b / gcd(b, c)) * c
想到一个东西
如果钦定 a = c，会怎么样
b ^ c = c + lcm(b, c)
如果 b 是 c 的倍数，且 b & c = 0，则相当于是 b + c = b ^ c
lcm(b, c) = b
*/

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

void solve() {
    LL a, b, c;
    cin >> c;
    a = c;
    b = c;
    while (( b & c ) != 0) {
        b <<= 1;
    }
    // assert((a ^ c) + (b ^ c) == lcm(a, c) + lcm(b, c));
    cout << a << " " << b << "\n";
}
