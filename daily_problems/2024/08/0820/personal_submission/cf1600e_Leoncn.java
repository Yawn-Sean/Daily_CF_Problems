
public class cf1600e_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int l = 0;
        while (l<n-1 && g[l+1] - g[l]>0){
            l++;
        }
        int r = n-1;
        while (r>0 && g[r-1] -g[r]>0){
            r--;
        }
        if( (((l + 1) | (n - r)) & 1) == 1) {
            out.println("Alice");
        }else {
            out.println("Bob");
        }
    }

}
