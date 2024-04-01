import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.InputMismatchException;

public class D {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    /**
     * https://codeforces.com/contest/1027/submission/254025475
     * 先拓扑，再求每个环的最小值
     */
    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }
    static ArrayList<Integer>[] g;
    public static void solve() {
        int n = sc.ni();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        int[] c = sc.na(n);
        int[] cntIn = new int[n];
        for (int i = 0; i < n; i++) {
            int to = sc.ni() - 1;
            cntIn[to]++;
            g[i].add(to);
        }
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            int tem = i;
            while (!vis[tem] && cntIn[tem]==0){
                vis[tem] = true;
                tem = g[tem].get(0);
                cntIn[tem]--;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(!vis[i]){
                int tem = i;
                int min = c[tem];
                while (!vis[tem]){
                    vis[tem] = true;
                    tem = g[tem].get(0);
                    min = Math.min(min, c[tem]);
                }
                ans += min;
            }
        }
        out.println(ans);
    }
}