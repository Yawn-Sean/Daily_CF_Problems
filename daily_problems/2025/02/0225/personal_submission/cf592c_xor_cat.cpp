#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;

std::istream &operator>>(std::istream &is, __int128 &val) {
    std::string s;
    bool flag = true;
    is >> s, val = 0;
    if (s[0] == '-') {
        flag = false;
        val = std::stoi(s.substr(0, 2));
        s = s.substr(2);
    }
    for (char &c : s) {
        val = val * 10 + (c - '0') * (!flag ? -1 : 1);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, __int128 val) {
    if (val < 0) {
        os << "-";
        val = -val;
    }
    if (val > 9) {
        os << val / 10;
    }
    os << static_cast<char>(val % 10 + '0');
    return os;
}

i128 _gcd(i128 a, i128 b) {
    if (a > b) {
        std::swap(a, b);
    }
    if (a == 0) {
        return b;
    }
    return _gcd(b % a, a);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i128 l, w, b;
    std::cin >> l >> w >> b;

    i128 lcm = (w * b / _gcd(w, b));
    i128 cnt = l / lcm;
    i128 min = std::min(w, b);
    i128 far = lcm * cnt;
    cnt *= min;
    cnt += std::min(l + 1, far + min) - far - 1;

    i128 g = _gcd(cnt, l);
    l /= g;
    cnt /= g;
    std::cout << cnt << "/" << l << "\n";

    return 0;
}
