#include <iostream>


int main() {
    std::string s;
    std::cin >> s;
    std::string S = s + s;
    int ans = 0;
    for (int i = 0, j = 0, n = S.size(); i < n; i = j) {
        for (j = i + 1; j < n && S[j] != S[j - 1]; j++);
        ans = std::max(ans, j - i);
    }
    std::cout << std::min(ans, (int)(S.size() >> 1)) << std::endl;
    return 0;
}
