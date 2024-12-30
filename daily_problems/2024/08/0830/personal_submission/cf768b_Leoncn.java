
public class cf768b_Leoncn {
    public static void solve() {
        long n = sc.nl();
        long l = sc.nl() -1;
        long r = sc.nl() - 1;
        out.println(dfs(n,l, r));
    }
    private static long dfs(long n, long l, long r){
        if (n == 0 || n ==1){
            return n;
        }
        int k = 64 - Long.numberOfLeadingZeros(n) - 1;
        long len = (1L << k) - 1;
        long ans = 0;
        if(l < len){
            ans += dfs(n/2, l, Math.min(r, len-1));
        }
        if(l<=len && r>=len){
            ans += n&1;
        }
        if(r>len){
            ans += dfs(n/2 , Math.max(0, l-len-1), r-len-1);
        }
        return ans;
    }
}
