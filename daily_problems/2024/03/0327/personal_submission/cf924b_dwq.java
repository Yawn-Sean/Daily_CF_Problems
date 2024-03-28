import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        String[] strs = s.split(" ");
        int n = Integer.parseInt(strs[0]);
        int u = Integer.parseInt(strs[1]);
        int[] nums = new int[n];
        int i = -1;
        s = in.readLine();
        strs = s.split(" ");
        for(String e : strs) nums[++i] = Integer.parseInt(e);
        // for(int e : nums) System.out.println(e);
        int l = 0, r = 0;
        double res = -1;
        while(l < n){
            
            while(r < n && nums[r] - nums[l] <= u) r += 1;
            if(r - l > 2) res = Max(res, 1.0 * (nums[r - 1] - nums[l + 1]) / (nums[r - 1] - nums[l]));
            l += 1;
        }
        out.println(res);
        out.flush();
    }
    public static double Max(double a, double b){
        
        return Double.compare(a, b) > 0 ? a : b;
    }
}
