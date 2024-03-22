import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        String s = in.readLine();
        String[] strs = s.split(" ");
        int n = Integer.parseInt(strs[0]);
        int k = Integer.parseInt(strs[1]);
        int i = -1;
        int[] cost = new int[n];
        s = in.readLine();
        strs = s.split(" ");
        for(String e : strs) cost[++i] = Integer.parseInt(e);
        for(i = 1; i < n; ++i) cost[i] = (int)Min(1l * cost[i], 2l * cost[i - 1]);
        long res = Long.MAX_VALUE, cur = 0;
        int div = 0;
        for(i = n - 1; i > -1; --i){
            
            res = Min(res, cur + cost[i] * 1l * ((k - 1) / (1 << i) + 1));
            div = k / (1 << i);
            // out.println(div + " " + cost[i]);
            // out.println(div << i);
            k -= div << i;
            cur += 1l * cost[i] * div;
        }
        out.println(res);
        out.flush();
    }
    public static int Max(int a, int b){ return a > b ? a : b; }
    public static long Min(long a, long b){ return Long.compare(a, b) < 0 ? a : b; }
}
