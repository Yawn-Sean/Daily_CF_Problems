import java.util.*;
import java.io.*;
public class Test{
    
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        s = s.replace("()", "0").replace("->", ",");
        int ln = s.length();
        int[] opStack = new int[ln];
        int p = -1, i = -1;
        int[] numbers = new int[ln];
        int x = 0, y = 0;
        
        for(char c : s.toCharArray()){
            
            if(c == '0') numbers[++i] = 0;
            else if(c == ',') opStack[++p] = 1;
            else if(c == '(') opStack[++p] = 0;
            else{
                
                while(opStack[p] > 0){
                    
                    x = numbers[i];
                    y = numbers[--i];
                    numbers[i] = Max(x,y + 1);
                    --p;
                }
                --p;
            }
        }
        
        while(p > -1){
            
            x = numbers[i];
            y = numbers[--i];
            numbers[i] = Max(x,y + 1);
            --p;
        }
        out.println(numbers[i]);
        out.flush();
    }
    public static int Max(int x, int y){ return x > y ? x : y;}

}
