void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s=" "+s;
 
 
    vector<int> l(k+2,inf),r(k+2,inf);
    for(int i=1;i<=k;i++){
        cin>>l[i];
    }
    for(int i=1;i<=k;i++){
        cin>>r[i];
    }
 
    vector<int> cnt(n+2,0);
    int q;
    cin>>q;
    while (q--){
        int c;
        cin>>c;
        cnt[c]^=1;
    }
 
    for(int i=1;i<=k;i++){
        int li=l[i],ri=r[i];
        int res=0;
        for(int j=li;j<=(ri+li)/2;j++){
            res^=cnt[j];
            res^=cnt[ri+li-j];
            if(res){
                swap(s[j],s[ri+li-j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<s[i];
    }
    cout<<endl;
 
}
