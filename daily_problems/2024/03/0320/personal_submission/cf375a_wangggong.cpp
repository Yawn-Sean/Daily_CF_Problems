#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const ll N = 1e6;
char s[N + 10];
string t = "1689";
string M[] = {
    "1869",
    "1968",
    "1689",
    "6198",
    "1698",
    "1986",
    "1896",
};
ll n, mod;

inline void _swap(ll k, char c) {
    for (ll i = 0, j = k; i < n; i++)
        if (s[i] == c) {
            swap(s[i], s[j]);
            return;
        }
}

bool all0() {
    for (ll i = 0; i < n - 4; i++)
        if (s[i] != '0') {
            swap(s[0], s[i]);
            return false;
        }
    return true;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (ll i = 0; i < 4; i++)
        _swap(n - 1 - i, t[i]);
    bool a0 = all0();
    for (ll i = 0; i < n - 4; i++)
        mod = (mod * 10 + (s[i] - '0')) % 7;
    mod = mod * 10000 % 7;
    mod = (7 - mod) % 7;
    if (a0)
        for (ll i = 0; i < n; i++)
            s[i] = i < 4 ? M[0][i] : '0';
    else
        for (ll i = 0; i < 4; i++)
            s[n - 4 + i] = M[mod][i];
    puts(s);
    return 0;
}
