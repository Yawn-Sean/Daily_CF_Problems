#include <bits/stdc++.h>
#include <bit>         
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned n;        
    std::cin>>n;

    for (unsigned i = 1; i <= n; ++i) {
        unsigned lb = i & -i;            
        char ch = char('a' + std::countr_zero(lb));
        cout << ch;
    }
    return 0;
}
