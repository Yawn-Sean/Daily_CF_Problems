public class cf1878d_Leoncn {
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
        char[] cs = sc.ns().toCharArray();
        int[][] g = new int[k][2];

        for (int i = 0; i < k; i++) {
            g[i][0] = sc.ni();
        }
        for (int i = 0; i < k; i++) {
            g[i][1] = sc.ni();
        }
        int q = sc.ni();
        int[] arr = sc.na(q);
        Arrays.sort(arr);
        int[] cnt = new int[n+1];
        int loc = 0;
        for (int i = 0; i < q; i++) {
            int c = arr[i];
            while (loc<k && g[loc][1]<c){
                loc++;
            }
            int min = Math.min(c, g[loc][0] + g[loc][1] - c);
            int max = Math.max(c, g[loc][0] + g[loc][1] - c);
            cnt[min-1]++;
            cnt[max]--;
        }
        int[] s = new int[n+1];
        for (int i = 0; i < n; i++) {
            s[i] = (i>0?s[i-1]:0) + cnt[i];
        }
        for (int i = 0; i < k; i++) {
            int a = g[i][0];
            int b = g[i][1];
            for (int j = a-1; j <=a + (b-a)/2 -1 ; j++) {
                if((s[j]&1)==1){
                    char tem = cs[b-1-(j-a+1)];
                    cs[b-1-(j-a+1)] = cs[j];
                    cs[j] = tem;
                }
            }
        }
        out.println(new String(cs));
    }
}
