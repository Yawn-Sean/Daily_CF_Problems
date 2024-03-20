import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        String s = null;
        String[] strs = null;
        int i = -1;
        
        while(--n > -1){
            
            s = in.readLine();
            strs = s.split(" ");
            int[] nums = new int[strs.length];
            for(String e : strs) nums[++i] = Integer.parseInt(e);
            int x = nums[0], y = nums[1];
            int p = nums[2], q = nums[3];
            if(p == 0) out.println(x == 0 ? 0 : -1);
            else if(p == q) out.println(x == y ? 0 : -1);
            else{
                y -= x;
                q -= p;
                out.println(Max((x - 1) / p  + 1, (y - 1) / q + 1) * 1l * (q + p) - (y + x));
            }
            i = -1;
        }
        out.flush();
    }
    public static int Max(int a, int b){ return a > b ? a : b; }
}
