#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],p[N];

void solve(){
    int n;cin>>n;
    std::vector<pair<int,int>> ans;

    auto cz=[&](int x,int y){
        swap(a[x],a[y]);
        p[a[x]]=x,p[a[y]]=y;

        //cout<<x<<" "<<y<<"ccc\n";
        //cout<<a[x]<<" "<<a[y]<<" "<<p[a[x]]<<" "<<p[a[y]]<<"  ccc\n";
        ans.emplace_back(x,y);
    };

    for(int i=1;i<=n;i++){
        cin>>a[i];p[a[i]]=i;
    }    
    
    for(int i=n/2;i>=1;i--){
        //cout<<a[i]<<"  pd\n";
        if(a[i]!=i){
            if(p[i]<=i){
                cz(p[i],n);
                cz(i,n);
            }
            else{
                if(2*abs(p[i]-i)>=n){
                    cz(i,p[i]);
                }
                else{
                    cz(p[i],1);
                    cz(p[i],n);
                    cz(p[i],i);
                }
            }    
        }

        //  for(int i=1;i<=n;i++){
        //     cout<<a[i]<<" ";
        // }
        //cout<<"\n  ########\n";

        //cout<<a[n-i+1]<<"   sd\n";
        if(a[n-i+1]==n-i+1)continue;
        if(n-i+1<=p[n-i+1]){
             cz(p[n-i+1],1);
             cz(n-i+1,1);
            
         }
        else{
            if(2*abs(n-i+1-p[n-i+1])>=n)
                cz(n-i+1,p[n-i+1]);
            else{
                //cout<<i<<" sdasd\n";
                cz(p[n-i+1],n);
                cz(p[n-i+1],1);
                cz(p[n-i+1],n-i+1);
            }
        }

        // for(int i=1;i<=n;i++){
        //     cout<<a[i]<<" ";
        // }
        //cout<<"\n  &&&&&\n";

    }
   


    cout<<ans.size()<<"\n";
    for(auto[x,y]:ans){
        cout<<x<<" "<<y<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
