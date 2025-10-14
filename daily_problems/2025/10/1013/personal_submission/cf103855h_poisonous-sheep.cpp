void solve()
{
      int n;
      cin>>n;
      vector<int> a(n+1);
      rep(1,n)cin>>a[i];
      int ans=1;
      int pos=1;
      int mx=a[1];
      rep(1,n){
            if(a[i]>mx){
                  ans*=(i-pos+1);
                  ans%=mod;
                  mx=a[i];
                  pos=i;
            }
      }
      cout<<ans<<endl;
}
