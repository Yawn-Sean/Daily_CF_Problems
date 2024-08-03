import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.InputMismatchException;

//https://codeforces.com/contest/1220/submission/254453922
public class D {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        long[] g = sc.nal(n);
        Map<Long,Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.merge(g[i] &-g[i], 1, Integer::sum);
        }
        int cnt = 0;
        long now = 0;
        for(long a : map.keySet()){
            if(map.get(a)>cnt){
                cnt = map.get(a);
                now = a;
            }
        }
        out.println(n - cnt);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if((g[i] & -g[i])!= now){
                sb.append(g[i]).append(" ");
            }
        }
        out.println(sb);

    }

}
