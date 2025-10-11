#include <bits/stdc++.h>
#define ll long long
#define MAXN 10000005
bool isnap[MAXN + 5];
std::vector<int> primes;
int pre[MAXN + 5];

void init(){
    for(int i = 2; i <= MAXN; ++i){
        if(!isnap[i]){
            primes.push_back(i);
        }
        for(int p :primes){
            if(p * i > MAXN){
                break;
            }
            isnap[p * i] = 1;
            if(i % p == 0){
                break;
            }
        }
    }
    for(int i = 2; i <= MAXN; ++i){
        pre[i] = pre[i - 1];
        if(!isnap[i]){
            pre[i]++;
        }
    }
}
void solve(){
    int n;
    std::cin >> n;
    if(n == 2){
        std::cout << "0\n";
        return;
    }
    if(n == 3){
        std::cout << "1\n";
        return;
    }
    int ans = pre[n] - pre[n / 2];
    std::cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    init();
    while(t--){
        solve();
    }
    std::cout << std::flush;
    return 0;
}