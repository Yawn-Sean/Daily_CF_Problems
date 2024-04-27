import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class C {
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
        int[][] g = sc.nmi(n,2);
        int min = Integer.MAX_VALUE, minS = Integer.MAX_VALUE, minLoc = -1;
        int max = -1, maxS = -1, maxLoc = -1;
        for (int i = 0; i < n; i++) {
            if(g[i][1]<min){
                minS = min;
                min = g[i][1];
                minLoc = i;
            }else if(g[i][1]<minS){
                minS = g[i][1];
            }
            if(g[i][0]>max){
                maxS = max;
                max = g[i][0];
                maxLoc = i;
            }else if(g[i][0]>maxS){
                maxS = g[i][0];
            }
        }
        if(minLoc == maxLoc){
            out.println(Math.max(0, minS-maxS));
        }else {
            out.println(Math.max(0, Math.max(min -maxS, minS - max)));
        }
    }

}