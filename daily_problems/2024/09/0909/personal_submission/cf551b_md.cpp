// 0909
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b, c;
    std::cin >> a >> b >> c;

    std::array<int, 26> freq_a{0}, freq_b{0}, freq_c{0};
    for (char ch : a) {
        ++freq_a[ch - 'a'];
    }
    for (char ch : b) {
        ++freq_b[ch - 'a'];
    }
    for (char ch : c) {
        ++freq_c[ch - 'a'];
    }

    int best_bcnt = 0;
    int best_ccnt = 0;
    for (int bcnt = 0; bcnt <= size(a) / size(b); ++bcnt) {
        int ccnt = 1e6;
        bool found = true;
        for (int ch = 0; ch < 26; ++ch) {
            if (freq_b[ch] * bcnt > freq_a[ch]) {
                found = false;
                break;
            }

            if (freq_c[ch] > 0) {
                ccnt = std::min(ccnt, (freq_a[ch] - freq_b[ch] * bcnt) / freq_c[ch]);
            }
        }

        if (found) {
            if (bcnt + ccnt > best_bcnt + best_ccnt) {
                best_bcnt = bcnt;
                best_ccnt = ccnt;
            }
        }
    }

    for (int i = 0; i < best_bcnt; ++i) {
        std::cout << b;
    }

    for (int i = 0; i < best_ccnt; ++i) {
        std::cout << c;
    }

    for (int ch = 0; ch < 26; ++ch) {
        freq_a[ch] -= freq_b[ch] * best_bcnt + freq_c[ch] * best_ccnt;
        for (int i = 0; i < freq_a[ch]; ++i) {
            std::cout << static_cast<char>('a' + ch);
        }
    }


    return 0;
}