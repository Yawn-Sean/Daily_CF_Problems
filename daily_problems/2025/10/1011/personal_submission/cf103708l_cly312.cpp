#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n+1),s(n+1),p(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ll x=(a[i]%M+M)%M;
        s[i]=(s[i-1]+x)%M;
        p[i]=(p[i-1]+s[i])%M;
    }
    vector<int> l(n+1),r(n+1,n+1),st;
    for(int i=1;i<=n;++i){
        while(!st.empty()&&a[st.back()]<=a[i])st.pop_back();
        l[i]=st.empty()?0:st.back();
        st.push_back(i);
    }
    st.clear();
    for(int i=n;i>=1;--i){
        while(!st.empty()&&a[st.back()]<=a[i])st.pop_back();
        r[i]=st.empty()?n+1:st.back();
        st.push_back(i);
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        ll cl=i-l[i],cr=r[i]-i;
        ll c1=(p[r[i]-1]-p[i-1]+M)%M;
        ll sl=p[i-1];
        if(l[i]>0) sl=(sl-p[l[i]-1]+M)%M;
        ll t1=cl%M*c1%M,t2=cr%M*sl%M,f=(t1-t2+M)%M;
        ans=(ans+f)%M;
    }
    cout<<ans<<'\n';
}
