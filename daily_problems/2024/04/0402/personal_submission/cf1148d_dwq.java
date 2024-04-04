import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int[] xs = new int[n];
        int[] ys = new int[n];
        int x = 0, y = 0, i = -1;
        int tn = n;
        String s = null;
        String[] strs = null;
        int count = 0;
        
        while(--tn > -1){
            
            s = in.readLine();
            strs = s.split(" ");
            x = Integer.parseInt(strs[0]);
            y = Integer.parseInt(strs[1]);
            xs[++i] = x;
            ys[i] = y;
            count = x > y ? count + 1 : count;
        }
        
        List<Integer> res = new ArrayList<>();
        if(count * 2 >= n){
            
            for(i = 0; i < n; ++i)
                if(xs[i] > ys[i]) res.add(i);
            Collections.sort(res, (a,b)->xs[a] - xs[b]);
        }else{
            
            for(i = 0; i < n; ++i)
                if(xs[i] < ys[i]) res.add(i);
            Collections.sort(res, (a,b)->ys[b] - ys[a]);
        }
        out.println(res.size());
        for(int e : res) out.print((e + 1) + " ");
        out.flush();
    }
}
