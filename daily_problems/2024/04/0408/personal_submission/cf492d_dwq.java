import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        String[] strs = s.split(" ");
        int n = Integer.parseInt(strs[0]);
        int x = Integer.parseInt(strs[1]);
        int y = Integer.parseInt(strs[2]);
        
        long res = 0;
        while(--n > -1){
            
            res = binarySearch(Integer.parseInt(in.readLine()) * 1l, x, y);
            // out.println(res);
            if(res % x == 0){
                if(res % y == 0) out.println("Both");
                else out.println("Vova");
            }else out.println("Vanya");
        }
        out.flush();
    }
    public static long binarySearch(long v, int x, int y){
        
        long left = 0, right = (long)1e15;
        long m = 0;
        while(Long.compare(left + 1, right) < 0){
            
            m = (left + right) >>> 1;
            if(Long.compare(m / x + m / y, v) >= 0) right = m;
            else left = m;
        }
        return right;
    }
}
