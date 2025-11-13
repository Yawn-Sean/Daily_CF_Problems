int op(int x, int y) {return x & y;}
int e() {return -1;}

void solve(){
    int n,k,q; cin >> n >> k >> q;
    VC nums(n);
    for(auto &i : nums) {
        cin >> i;
        if((i & k) == k) i -= k;
        else i = -1;
    }

    atcoder::segtree<int, op , e> seg(nums);
    while(q --) {
        int l,r; cin >> l >> r;
        cout << (seg.prod(l-1, r) ? "No":"Yes") << endl;
    }
}
