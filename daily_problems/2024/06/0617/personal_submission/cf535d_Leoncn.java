
public class cf535d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        String s = sc.ns();
        char[] cs = s.toCharArray();
        int[] g = sc.na(m);
        int[] z = zFunctionTrivial(s);
        for (int i = 0; i < m-1; i++) {
            if(g[i+1] - g[i] < cs.length){
                int c = cs.length - (g[i+1] - g[i]);
                if(z[cs.length-c] != c){
                    out.print(0);
                    return;
                }
            }
        }
        int f = 1;
        long ans = 1;
        for (int i = 0; i < m; i++) {
            while (f<g[i]){
                ans = ans * 26 % (1000000007);
                f++;
            }
            f = g[i] + cs.length;
        }
        while (f<=n){
            ans = ans * 26 % (1000000007);
            f++;
        }
        out.print(ans);
    }
    public static int[] zFunctionTrivial(String word){
        char[] s = word.toCharArray();
        int n = word.length();
        int[] z = new int[n];
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r && z[i - l] < r - i + 1) {
                z[i] = z[i - l];
            } else {
                z[i] = Math.max(0, r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            }
            if (i + z[i] - 1 > r) {l = i; r = i + z[i] - 1;}
        }
        return z;
    }
}
