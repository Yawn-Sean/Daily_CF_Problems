void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n+1);
    rep(1,n)cin>>a[i];
    int ct=min(l-1,n-r);
    priority_queue<int> pq;
    rep(1,n-ct){
        pq.push(a[i]);
    }
    ct=r-l+1;
    int sum=0;
    while(ct--){
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum<<endl;
}
