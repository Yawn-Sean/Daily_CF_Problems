import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int[] nums = new int[n];
        String s = in.readLine();
        String[] strs = s.split(" ");
        int i = -1;
        for(String e : strs) nums[++i] = Integer.parseInt(e);
        int max = Max(nums) + 1;
        int[] map = new int[max];
        for(int e : nums) ++map[e];
        int[] dp = new int[max];
        int j = 0;
        for(i = 1; i < max; ++i){
            
            dp[i] += map[i];
            for(j = i; j < max; j += i)
                dp[j] = dp[i] > dp[j] ? dp[i] : dp[j];
        }
        out.println(Max(dp));
        out.flush();
    }
    public static int Max(int[] arr){
        
        int max = 0;
        for(int e : arr) max = max > e ? max : e;
        return max;
    }
}
