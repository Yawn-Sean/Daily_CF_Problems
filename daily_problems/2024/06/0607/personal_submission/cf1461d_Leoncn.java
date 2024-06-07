    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }
  public static void solve() {
        int n = sc.ni();
        int q = sc.ni();
        int[] g = sc.na(n);
        Arrays.sort(g);
        Set<Long> sum = new HashSet<>();
        long[] s = new long[n];
        s[0] = g[0];
        for(int i=1;i<n;i++){
            s[i] = s[i-1] +  g[i];
        }
        dfs(0,n-1, s, sum,g);
        for(int i=0;i<q;i++){
            long f  = sc.nl();
            if(sum.contains(f)) {
                out.println("Yes");
            }else{
                out.println("No");
            }
        }
    }
    static long sums(int l,int r, long[] s){
        if(l!=0){
            return s[r] - s[l-1];
        }

        return s[r];
    }

    static int binaryResearch(int l,int r,int val, int[] g){
        int mid = (l + r) / 2;
        if(r==l+1) return l;

        if(g[mid]<=val){
            return binaryResearch(mid,r,val, g);
        }
        return binaryResearch(l,mid,val, g);
    }

    static void dfs(int l,int r, long[] s, Set<Long> sum, int[] g){

        sum.add(sums(l,r, s));
        if(g[l]==g[r]) return ;

        int mid = (g[l] + g[r]) / 2;

        mid = binaryResearch(l,r,mid,g);

        dfs(l,mid,s, sum,g);
        dfs(mid+1,r,s, sum,g);

    }
