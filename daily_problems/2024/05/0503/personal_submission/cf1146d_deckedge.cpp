#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxn = 3e5+10;
bool vis[maxn];
int ans = 0;
LL m,a,b;

LL gcd(int a, int b) {
    return !b ? a : gcd(b, a % b); 
}

void bfs(int x){
    if(vis[x]) return ;
    queue<int> q;
    q.push(x);
    vis[x] = 1,ans++;
    while(!q.empty()){
        int p = q.front();q.pop();
        if(p+a < x && !vis[p+a])
            q.push(p+a),vis[p+a] = 1,ans++;
        if(p-b > 0 && !vis[p-b])
            q.push(p-b),vis[p-b] = 1,ans++;
    }
}
LL Get(LL n){
    LL d = gcd(a,b);
    return n/d*(m+1)-(n/d)*(n/d+1)/2*d;
}
int main(void)
{
    cin>>m>>a>>b;
    LL cnt = 0;
    vis[0] = 1;
    ans = 1;
    for(int i = 0;i <= min(a+b,m); ++i){
        if(i-a>= 0&&vis[i-a])
            bfs(i);
        // cout<<i<<" "<<vis[2]<<endl;
        // cout<<i<<" "<<ans<<endl;
        cnt += ans;
    }
    LL Ans = cnt;
    // cout<<cnt<<endl;
    if(m > a+b){
        Ans += Get(m);
        Ans += (m-(a+b))*ans;
        Ans -= Get(a+b);
        // cnt -= Get(a+b);
    }
    cout<<Ans<<endl;
    

   return 0;
}

