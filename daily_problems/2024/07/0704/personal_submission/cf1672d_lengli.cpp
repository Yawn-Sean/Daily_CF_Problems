/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),b(n+2),cnt(n+2),use(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i],cnt[a[i]]++;
    for(int i=1;i<=n;i++) std::cin>>b[i];
    if(b[n]!=a[n]){
        std::cout<<"NO"<<"\n";
        return;
    }
    int la=a[n];cnt[la]--;
    bool flag=1;
    for(int i=n-1,j=n-1;i>=1 and j>=1;i--,j--){
        if(a[i]==b[j]){
            if(!cnt[a[i]]){
                flag=0;
                break;
            }
            la=a[i];
            cnt[a[i]]--;
        }else{
            if(b[j]==la){
                if(cnt[b[j]]) {
                    cnt[b[j]]--;
                    use[b[j]]++;
                    i++;
                }else{
                    flag=0;
                    break;
                }
            }else{
                if(use[a[i]]){
                    use[a[i]]--;
                    j++;
                }else{
                    flag=0;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]) {
            flag=0;
        }
    }
    std::cout<<(flag ? "YES" : "NO")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
