#include <iostream>
#include <utility>
#include <string>
#include <typeinfo>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <queue>
#include <iterator>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans(n + 1);
    for(int i = 0; i <= n; ++i){
        ans[i] = i;
    }
    auto f = [&](auto self, int l, int r)->void{
        if(l > r){
            return;
        }
        int len = r - l + 1;
        int v = 1 << (31 - __builtin_clz(len));

        for (int i = l; i <= r - v; i ++)
            ans[i] ^= v;
        
        for (int i = l + v; i <= r; i ++)
            ans[i] ^= v;
        
        for (int i = r - v + 1; i <= r; i ++)
            ans[i] ^= v - 1;
        
        self(self, l, r - v);
    };
    f(f, 0, n);
    std::cout << 1ll * n * (n + 1) << std::endl;
    for(int i = 0; i <= n; ++i){
        std::cout << ans[i] << " ";
    }


}