import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        String s = in.readLine();
        String[] strs = s.split(" ");
        int key = 1 << 20;
        int[] nums = new int[n];
        int i = -1, t = 0;
        for(String e : strs) nums[++i] = Integer.parseInt(e) ^ key;
        
        HashMap<Integer, Integer> left = new HashMap<>();
        HashMap<Integer, Integer> right = new HashMap<>();
        for(i = 0; i < n; ++i){
            
            t = nums[i];
            if(!left.containsKey(t)) left.put(t, i);
            right.put(t, i);
        }
        int[] diff = new int[n];
        for(int k : left.keySet()){
            
            diff[left.get(k)] += 1;
            diff[right.get(k)] -= 1;
        }
        long res = 1;
        int mod = 998244353;
        for(i = 0; i < n - 1; ++i){
            
            diff[i + 1] += diff[i];
            if(diff[i] == 0) res = res * 2 % mod;
        }
        out.println(res);
        out.flush();
    }
    public static int Max(int a, int b){ return a > b ? a : b; }
    public static int Min(int a, int b){ return a < b ? a : b; }
}
