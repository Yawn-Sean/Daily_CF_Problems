import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int tn = n, i = -1;
        String s = null;
        String[] strs = null;
        int[][] pos = new int[n][2];
        while(--tn > -1){
            
            s = in.readLine();
            strs = s.split(" ");
            pos[++i][0] = Integer.parseInt(strs[0]);
            pos[i][1] = Integer.parseInt(strs[1]);
        }
        
        double d = Long.MAX_VALUE;
        int j = 0, k = 0;
        double dx = 0, dy = 0;
        double dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
        for(i = -1; i < n - 1; ++i){
            
            j = (i - 1 + n) % n;
            dx = pos[i + 1][0] - pos[j][0];
            dy = pos[i + 1][1] - pos[j][1];
            k = (i + n) % n;
            dx1 = pos[k][0] - pos[j][0];
            dy1 = pos[k][1] - pos[j][1];
            dx2 = pos[i + 1][0] - pos[k][0];
            dy2 = pos[i + 1][1] - pos[k][1];
            
            d = Min(d, Abs(dx1 * dy2 - dx2 * dy1) / Math.sqrt(dx * dx + dy * dy));
        }
        out.println(d / 2);
        out.flush();
    }
    public static double Min(double a, double b){ return Double.compare(a, b) < 0 ? a : b; }
    public static double Abs(double a){ return Double.compare(a, 0l) < 0 ? -a : a; }
}
