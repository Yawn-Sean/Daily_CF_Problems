
public class cf622d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] ans = new int[2*n];
        for (int i = 0; i < n/2; i++) {
            ans[i] = i * 2 + 1;
            ans[n-i-1] = i * 2 + 1;
            ans[n+i] = 2*(i+1);
            ans[2*n - 2- i] = 2*(i+1);
        }
        for(int a: ans){
            out.print( (a == 0?n:a) + " ");
        }
    }

}
