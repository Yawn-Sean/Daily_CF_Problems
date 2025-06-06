/* 
	xa+yb = n   -- x个a大小的圈 + y个b大小的圈
	x,y 可以枚举得到
*/ 

void solve(){
    int n,a,b; cin >> n >> a >> b;
    int ok = -1;
    if(a > b) swap(a,b);
    
    VC ans(n+1); iota(all(ans),0ll);

    auto change = [&](int l, int r){
        if(l < 0 || r > n) return;
        int t = ans[r];
        Rof(i,r,l+1) ans[i] = ans[i-1];
        ans[l] = t;
    };

    For(i,0,n/b){
        if((n-b*i)%a == 0) {ok = i; break;}
    }

    if(ok == -1) return void(cout << -1 << endl);
    
    For(i,0,ok-1){
        change(b*i + 1, b*i+b);
    }

    For(i,b*ok+1,n){
        change(i, i+a-1);
        i+=a-1;
    }

    For(i,1,n) cout << ans[i] << ' ';
}
