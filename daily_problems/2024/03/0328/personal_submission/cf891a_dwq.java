import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int[] arr = new int[n];
        String s = in.readLine();
        String[] strs = s.split(" ");
        int i = -1, j = 0, t = 0, oneCount = 0;
        for(String e : strs){
            
            t = Integer.parseInt(e);
            arr[++i] = t;
            oneCount = t == 1 ? oneCount + 1 : oneCount;
        } 
        if(oneCount > 0){
            
            out.println(n - oneCount);
        }else{
            oneCount = Integer.MAX_VALUE;
            for(i = 0; i < n; ++i){
                
                t = arr[i];
                for(j = i + 1; j < n; ++j){
                    
                    t = gcd(t , arr[j]);
                    if(t == 1){
                        
                        oneCount = oneCount < j - i ? oneCount : j - i;
                        break;
                    }
                }
            }
            out.println(oneCount == Integer.MAX_VALUE ? -1 : oneCount + n - 1);
        }
        out.flush();
    }
    public static int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
}
