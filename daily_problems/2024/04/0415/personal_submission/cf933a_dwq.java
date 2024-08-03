import java.util.*;
import java.io.*;
public class Test{
    
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int t = 0, dp1 = 0, dp12 = 0, dp121 = 0, dp1212 = 0;
        String s = in.readLine();
        String[] strs = s.split(" ");
        for(String e : strs){
            
            t = Integer.parseInt(e);
            if(t == 1){
              
              dp1 += 1;
              dp121 += 1;
            }else{
                
                dp12 += 1;
                dp1212 += 1;
            }
            dp12 = Max(dp1, dp12);
            dp121 = Max(dp12, dp121);
            dp1212 = Max(dp121, dp1212);
        }
        out.println(dp1212);
        out.flush();
    }
    public static int Max(int a, int b){ return a > b ? a : b; }
}
