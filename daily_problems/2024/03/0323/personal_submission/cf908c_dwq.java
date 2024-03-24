import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        String s = in.readLine();
        String[] strs = s.split(" ");
        int n = Integer.parseInt(strs[0]);
        int r = Integer.parseInt(strs[1]);
        s = in.readLine();
        strs = s.split(" ");
        int i = -1;
        int[] xs = new int[n];
        for(String e : strs) xs[++i] = Integer.parseInt(e);
        
        double[] res = new double[n];
        Arrays.fill(res, r);
        int j = 0, sub = 0;
        for(i = 0; i < n; ++i)
            for(j = 0; j < i; ++j){
                
                sub = xs[i] - xs[j];
                if(Abs(sub) > 2 * r) continue;
                res[i] = Max(res[i], res[j] + Math.sqrt(4 * r * r - sub * sub));
            }
        for(double e : res) out.print(e + " ");
        out.flush();
    }
    public static int Abs(int a){ return a > 0 ? a : -a; }
    public static double Max(double a, double b){
        
        return Double.compare(a, b) > 0 ? a : b;
    }
}
