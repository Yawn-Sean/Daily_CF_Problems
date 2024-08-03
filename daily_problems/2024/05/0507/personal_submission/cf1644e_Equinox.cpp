#include <bits/stdc++.h>
using i64 = long long;
const int N = 2e5 + 10;
std::string s;

void solve(){
    i64 n;
    std::cin >> n >> s;
    int len = s.size();
    i64 res = 0;
    int j = s.find('R');
    if (j == -1) {
        std::cout << n << '\n';
        return;
    }
    res = j * (n - 1);
    for(int i = len - 1, t = 0; i >= j; i --){
        if(s[i] == 'D') res += t;
        else t ++;
    }
    j = s.find('D');
    if (j == -1) {
        std::cout << n << '\n';
        return;
    }
    res += j * (n - 1);
    for(int i = len - 1, t = 0; i >= j; i --){
        if(s[i] == 'R') res += t;
        else t ++;
    }
    std::cout << n * n - res << '\n';
}


int main(){
    int _ = 1;
    std::cin >> _;
    while(_ --)
        solve();

    return 0;
}