void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<bool> vis(n+1,0);
    vector<int> ans;
    rep(1,n)cin>>a[i];
    int ct=n;
    rep(1,n){
        int ctt=ct;
        int e=0;
        for(int j=n;j>=1;j--){
            if(vis[j])continue;
            if(a[j]==ctt){
                e=a[j];
                vis[j]=1;
                break;
            }
            ctt--;
        }
        ct--;
        //cout<<e<<endl;
        if(e){
            ans.push_back(e);
        }
        else {
            cout<<"NO\n";
            return;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"YES\n";
    for(auto i: ans)cout<<i<<" ";
    cout<<endl;
}
