#include <iostream>

char f[51][51];

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= 25; j++) {
            f[i][j] = 'A'; 
            f[i][j + 25] = 'B';
            f[i + 25][j] = 'C';
            f[i + 25][j + 25] = 'D';
        }        
    }

    a--, b--, c--, d--;
    for (int i = 1; i <= 25; i += 2) {
        if (!d) break;
        for (int j = 1; j <= 25; j += 2) {
            if (!d) break;
            f[i][j] = 'D';
            d--;
        }
    }
    for (int i = 1; i <= 25; i += 2) {
        if (!c) break;
        for (int j = 26; j <= 50; j += 2) {
            if (!c) break;
            f[i][j] = 'C';
            c--;
        }
    }
    for (int i = 26; i <= 50; i += 2) {
        if (!b) break;
        for (int j = 1; j <= 25; j += 2) {
            if (!b) break;
            f[i][j] = 'B';
            b--;
        }
    }
    for (int i = 26; i <= 50; i += 2) {
        if (!a) break;
        for (int j = 26; j <= 50; j += 2) {
            if (!a) break;
            f[i][j] = 'A';
            a--;
        }
    }
    std::cout << 50 << ' ' << 50 << '\n';
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <=50; j++) {
            std::cout << f[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}
