package daily_problems.2024.02.0226.personal_submission;

public class cf1547e_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
 
    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }
 
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int[] a = sc.na(k);
        int[] t = sc.na(k);
        int[] ans = new int[n+2];
        Arrays.fill(ans, Integer.MAX_VALUE/2);
        for (int i = 0; i < k; i++) {
            ans[a[i]] = t[i];
        }
        for (int i = 1; i <=n ; i++) {
            ans[i] = Math.min(ans[i-1]+1, ans[i]);
        }
        for (int i = n; i >=1 ; i--) {
            ans[i] = Math.min(ans[i+1]+1, ans[i]);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <=n ; i++) {
            sb.append(ans[i]).append(" ");
        }
        out.println(sb);
    }
    
}
