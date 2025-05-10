#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::cout<<n+n/2<<'\n';

    for(int i=2;i<=n;i+=2) 
		std::cout<<i<<" ";

    for(int i=1;i<=n;i+=2) 
		std::cout<<i<<" ";

    for(int i=2;i<=n;i+=2) 
		std::cout<<i<<" ";

    return 0;
}