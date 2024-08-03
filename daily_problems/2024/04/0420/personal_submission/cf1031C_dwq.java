import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        String[] strs = s.split(" ");
        int a = Integer.parseInt(strs[0]);
        int b = Integer.parseInt(strs[1]);
        
        //(sqrt(b^2 - 4ac) - b) / 2a
        int x = (int)(Math.sqrt(8l * a + 1) - 1) / 2;
        List<Integer> splitOne = new ArrayList<>();
        int i = 1;
        long sum = (x + 1l) *  x / 2;
        for(; i <= x; ++i) splitOne.add(i);
        a -= sum;
        for(i = x - 1; i > -1; --i){
            
            if(a == 0) break;
            splitOne.set(i, splitOne.get(i) + 1);
            --a;
        }
        
        int t = x + 1;
        for(i = 0; i < x; ++i)
            if(splitOne.get(i) != i + 1){
                
                t = i + 1;
                break;
            }
        List<Integer> splitTwo = new ArrayList<>();
        if(t <= b){
            
            b -= t;
            splitTwo.add(t);
        }
        for(i = x + 2; ; ++i){
            
            if(i > b) break;
            b -= i;
            splitTwo.add(i);
        }
        out.println(splitOne.size());
        for(int e : splitOne) out.print(e + " ");
        out.println();
        out.println(splitTwo.size());
        for(int e : splitTwo) out.print(e + " ");
        out.flush();
    }
}
