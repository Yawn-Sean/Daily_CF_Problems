import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int len = 2 * n - 1;
        int[] arr = new int[len];
        int i = -1, t = 0, count = 0, min = 1001, sum = 0;
        String s = in.readLine();
        String[] strs = s.split(" ");
        for(String e : strs){
            
            t = Integer.parseInt(e);
            arr[++i] = t;
            if(t < 0){
                
                ++count;
                t = -t;
            }
            min = min < t ? min : t;
            sum += t;
        }
        if((count & 1) == 0) out.println(sum);
        else if((n & 1) == 1) out.println(sum);
        else out.println(sum - 2 * min);
        out.flush();
    }
}
