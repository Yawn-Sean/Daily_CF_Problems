import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        String[] strs = s.split(" ");
        long n = Long.parseLong(strs[0]);
        long b = Long.parseLong(strs[1]);
        long t = 2, count = 0;
        List<long[]> prime_arr = new ArrayList<>();
        for(; t <= b; ++t){
            
            if(Long.compare(t * t,  b) > 0) break;
            if(b % t == 0){
                
                count = 0;
                while(b % t == 0){
                    ++count;
                    b /= t;
                }
                prime_arr.add(new long[]{t, count});
            }
        }
        if(b > 1) prime_arr.add(new long[]{b, 1});
        
        long res = Long.MAX_VALUE;
        for(long[] e : prime_arr){
            
            t = n;
            count = 0;
            while(t > 0){
                
                t /= e[0];
                count += t;
            }
            res = Long.compare(res, count / e[1]) < 0 ? res : count / e[1];
        }
        out.println(res);
        out.flush();
    }
}
