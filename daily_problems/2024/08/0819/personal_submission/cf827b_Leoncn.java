public class cf827b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int a = (n - 1)/k;
        int b = (n-1)%k;
        out.println(2*a + Math.min(2, b));
        for (int i = 1; i < k+1; i++) {
            out.println( i + " " + n);
        }
        for (int i = k+1; i <n; i++) {
            out.println(i + " "  + (i-k));
        }
    }
}
