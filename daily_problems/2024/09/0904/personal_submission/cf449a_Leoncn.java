
public abstract class cf449a_Leoncn {
    public static void solve() {
        long n = sc.ni();
        long m = sc.ni();
        long k = sc.ni();
        if((n-1)+(m-1)< k){
            out.println(-1);
            return;
        }
        if(n<m){
            long x = n;
            n = m;
            m = x;
        }
        long ans = -1;
        if(k<=m-1){
            ans = Math.max(n/(k+1) *m, m/(k+1)*n);
        }else if(k>m-1 && k<=n-1){
            ans = n/(k+1)*m;
        }else {
            ans = m/(k-n+2);
        }
        out.println(ans);
    }
}
