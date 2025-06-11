    void solve() {
        int t = ni();
        while(t-- > 0) {
            int n = ni();
            pair a[] = new pair[n];
            for(int i = 0; i < n; i++) {
                int h = ni(), w = ni();
                if(h > w) {
                    h ^= w; w ^= h; h ^= w;
                }
                a[i] = new pair(h, w, i);
            }
        Arrays.sort(a, (pair u, pair v) -> (u.H != v.H ? (u.H - v.H) : (v.W - u.W)));
        int ans[] = new int[n];
        pair d = a[0], s = null;
        ans[a[0].I] = -1;
        for(int i = 1; i < n; i++) {
            if(d.H < a[i].H && (s == null || d.W < s.W))    s = d;
            if(d.W > a[i].W) d = a[i];
 
            if(s != null && s.W < a[i].W)   ans[a[i].I] = s.I + 1;
            else    ans[a[i].I] = -1;
        }
        for(int x : ans)    out.print(x +" ");
        out.println();
        }
    }
