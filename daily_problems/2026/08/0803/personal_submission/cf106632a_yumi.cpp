#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005

bool isPrime(int x){
    if(x < 2)   return false;
    for(int i = 2;i * i <= x;i++){
        if(x % i == 0)  return false;
    }
    return true;
}
int cnt[MAXN];
void build(){
    cnt[1] = 1;
    for(int i = 2;i < MAXN;i++){
        if(isPrime(i))  cnt[i] = 1;
        else{
            int sq = sqrt(i);
            if(sq * sq == i)    cnt[i] = cnt[sq];
        }
    }
    for(int i = 2;i < MAXN;i++){
        cnt[i] += cnt[i - 1];
    }
}

void solve(){
    int m;
    cin >> m;
    cout << cnt[m] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    build();
    while(T--){
        solve();
    }
    return 0;
}