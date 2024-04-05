import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
       
        String s = in.readLine();
        String[] strs = s.split(" ");
        int n = Integer.parseInt(strs[0]);
        int m = Integer.parseInt(strs[1]);
        int[] nums = new int[n + 1];
        int i = 0;
        s = in.readLine();
        strs = s.split(" ");
        for(String e : strs) nums[++i] = Integer.parseInt(e);
        
        double res = 0;
        while(--m > -1){
            
            s = in.readLine();
            strs = s.split(" ");
            res = Max(res, (nums[Integer.parseInt(strs[0])] + nums[Integer.parseInt(strs[1])]) * 1.0 /
                           Integer.parseInt(strs[2]));
        }
        out.println(res);
        out.flush();
    }
    public static double Max(double a, double b){ return Double.compare(a, b) > 0 ? a : b; }
}
