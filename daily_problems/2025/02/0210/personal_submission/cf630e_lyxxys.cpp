void solve(){
    auto call = [&](int x, int y1, int y2)->int{
        bool jg = abs(x)%2 == abs(y1)%2;
        if (jg){
            return 1+(y2-y1)/2;
        } else {
            return y2-y1 > 0 ? 1+(y2-y1-1)/2 : 0;
        }
    };
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    const i64 l1 = (x2-x1+2)/2, l2 = (x2-x1+1)/2;
    i64 v1 = call(x1, y1, y2), v2 = call(x1+1, y1, y2);
    // cout << l1*v1 << "\n";
    cout << l1*max(v1,v2)+l2*min(v1,v2) << "\n";

}
