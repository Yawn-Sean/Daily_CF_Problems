#include<bits/stdc++.h>
void solve(){
    int d, m;
    scanf("%d%d",&d, &m);
    long long answer=1;
    for(int i = 0; i < 30; i++) {
        if(d < (1 << i)) break;
        answer = answer * (std::min((1 << (i+1)) - 1, d) - (1 << i) + 2) % m;
    }
    answer--;
    if(answer < 0) answer += m;
    printf("%lld\n",answer);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}
