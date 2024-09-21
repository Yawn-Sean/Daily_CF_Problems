
public class cf852c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int[][] arr = new int[n][2];
        for (int i = 0; i < n-1; i++) {
            arr[i][0] = n- g[i] - g[i+1];
            arr[i][1] = i;
        }
        arr[n-1][0] = n - g[n-1] - g[0];
        arr[n-1][1] = n-1;
        Arrays.sort(arr, (a, b)->a[0]-b[0]);
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[arr[i][1]] = n-1-i;
        }
        for(int a: ans){
            out.print( a + " ");
        }
    }
}
