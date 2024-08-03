import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int len = 0, dx = 0, dy = 0, g = 0;
        Map<String, Integer> map = null;
        String s = null,  key = null;
        String[] strs = null;
        long res = 0;
        while(--n > -1){
            
            len = Integer.parseInt(in.readLine());
            // out.println(len);
            map = new HashMap<String, Integer>();
            res = 0;
            while(--len > -1){
                
                s = in.readLine();
                // out.println(s);
                strs = s.split(" ");
                dx = Integer.parseInt(strs[2]) - Integer.parseInt(strs[0]);
                dy = Integer.parseInt(strs[3]) - Integer.parseInt(strs[1]);
                g = gcd(dx, dy);
                g = g < 0 ? -g : g;
                dx /= g;
                dy /= g;
                key =  (-1 * dx) + "_" + (-1 * dy);
                // out.println(g + " " + key + " pre " + map.getOrDefault(key, 0));
                res += map.getOrDefault(key, 0);
                key = dx + "_" + dy;
                map.merge(key, 1, Integer::sum);
                // out.println(key + " cur");
            }
            out.println(res);
        }
        out.flush();
    }
    public static int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
}
