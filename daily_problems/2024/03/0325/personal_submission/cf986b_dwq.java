import java.util.*;
import java.io.*;
public class Test{
    
    public static class FenWickTree{
        
        long[] nums;
        int n;
        public FenWickTree(int n){
            
            this.n = n;
            nums = new long[n];
        }
        public long sum(int i){
            
            long res = 0;
            while(i > 0){
                
                res += nums[i];
                i &= i - 1;
            }
            return res;
        }
        public void add(int i, int delta){
            
            while(i < n){
                
                nums[i] += delta;
                i += i & -i;
            }
        }
    }
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        String s = in.readLine();
        String[] strs = s.split(" ");
        FenWickTree ftree = new FenWickTree(n + 1);
        long count = 0;
        int  t = 0;
        int i = n - 1;
        for(; i > -1; --i){
            
            t = Integer.parseInt(strs[i]);
            count += ftree.sum(t);
            ftree.add(t, 1);
        }
        out.println(((count - n) & 1) == 1 ? "Um_nik" : "Petr");
        out.flush();
    }
    
}
