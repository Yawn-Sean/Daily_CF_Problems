public class cf476d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        out.println(k *(6*n-1));
        int[] g = {1,2,3,5};
        for (int i = 0; i < n; i++) {
            for(int w: g){
                out.print( (6 * i + w) * k  + " ");
            }
            out.println("");
        }
    }
}
