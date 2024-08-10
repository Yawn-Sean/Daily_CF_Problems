import java.util.Arrays;

public class cf231c_Leoncn {
        public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        long[] g = sc.nal(n);
        Arrays.sort(g);
        int loc = 0;
        long sum = 0;
        int ans = 1;
        long res = g[0];
        for (int i = 1; i < n; i++) {
            sum += (g[i] - g[i-1])*(i-loc);
            while (sum>k){
                sum -= g[i] - g[loc];
                loc++;
            }
            if(i-loc+1>ans){
                ans = i -loc + 1;
                res = g[i];
            }

        }
        out.println(ans + " " + res);
    }
}
