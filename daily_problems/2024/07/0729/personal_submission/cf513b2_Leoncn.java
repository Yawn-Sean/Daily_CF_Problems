
public class cf513b2_Leoncn {
    
    public static void solve() {
        int n = sc.ni();
        long k = sc.nl() - 1;
        int[] ans = new int[n];
        int l = 0, r = n-1;
        for (int i = 1; i < n; i++) {
            if((k>>(n-i-1) & 1)==1){
                ans[r--] = i;
            }else {
                ans[l++] = i;
            }
        }
        ans[l] = n;
        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
        }
    }

}
