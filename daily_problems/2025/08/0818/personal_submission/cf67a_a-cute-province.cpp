#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
/*
    双向扫描, 扫描一次先满足=R的再去扫描一次调整满足L=
*/
int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> toffees(n, 1);


    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'R') {
            toffees[i + 1] = toffees[i] + 1;
        } else if (s[i] == '=') {
            toffees[i + 1] = toffees[i];
        }
    }

 
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == 'L') {
         
            toffees[i] = std::max(toffees[i], toffees[i + 1] + 1);
        } else if (s[i] == '=') {
           
            toffees[i] = std::max(toffees[i], toffees[i + 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << toffees[i] << (i == n - 1 ? "" : " ");
    }

    return 0;
}
