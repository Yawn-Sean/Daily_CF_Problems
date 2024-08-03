import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int n = Integer.parseInt(in.readLine());
        int[] ls = new int[n];
        int[] rs = new int[n];
        String s = null;
        String[] strs = null;
        int t = n, i = -1;
        while(--t > -1){
            
            s = in.readLine();
            strs = s.split(" ");
            ls[++i] = Integer.parseInt(strs[0]);
            rs[i] = Integer.parseInt(strs[1]);
        }
        int[] presMaxL = new int[n];
        Arrays.fill(presMaxL, Integer.MIN_VALUE);
        int[] presMinR = new int[n];
        Arrays.fill(presMinR, Integer.MAX_VALUE);
        for(i = 0; i < n - 1; ++i){
            
            presMaxL[i + 1] = Max(presMaxL[i], ls[i]);
            presMinR[i + 1] = Min(presMinR[i], rs[i]);
        }
        
        int suffMaxL = Integer.MIN_VALUE;
        int suffMinR = Integer.MAX_VALUE;
        int res = 0;
        for(i = n - 1; i > -1; --i){
            
            res = Max(res, Min(suffMinR, presMinR[i]) - Max(suffMaxL, presMaxL[i]));
            suffMaxL = Max(suffMaxL, ls[i]);
            suffMinR = Min(suffMinR, rs[i]);
        }
        out.println(res);
        out.flush();
    }
    public static int Max(int a, int b){ return a > b ? a : b; }
    public static int Min(int a, int b){ return a < b ? a : b; }
}
