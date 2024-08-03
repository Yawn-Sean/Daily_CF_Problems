import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringBuilder x = new StringBuilder(in.readLine());
        StringBuilder y = new StringBuilder(in.readLine());
        int xn = x.length(), yn = y.length();
        int max = xn > yn ? xn : yn;
        int t = max - xn;
        while(--t > -1) x.insert(0, '0');
        t = max - yn;
        while(--t > -1) y.insert(0, '0');
        // out.println(x.toString());
        // out.println(y.toString());
        int a = 0, b = 0;
        for(t = 0; t < max; ++t){
            
            xn = a + b;
            yn = a + x.charAt(t) - y.charAt(t);
            a = xn;
            if(a > 1){
                
                out.println(">");
                out.flush();
                return;
            } 
            if(a < -1){
                
                out.println("<");
                out.flush();
                return;
            } 
            b = yn;
        }
        if(a == b && a == 0) out.println("=");
        else{
            
            while(Abs(a) < 2){
                
                xn = a + b;
                yn = a;
                a = xn;
                b = yn;
            }
            out.println(a > 0 ? ">" : "<");
        }
        out.flush();
    }
    public static int Abs(int a){ return a > 0 ? a : -a; }
}
