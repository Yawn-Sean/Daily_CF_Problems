import java.util.*;
import java.io.*;
public class Test{
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        String[] strs = s.split(" ");
        int n = Integer.parseInt(strs[0]);
        int k = Integer.parseInt(strs[1]);
        List<Integer> winterSub = new ArrayList<>();
        List<Integer> lastSub = new ArrayList<>();
        s = in.readLine();
        strs = s.split(" ");
        int t = 0, count = 0;
        for(String e : strs){
            
            t = Integer.parseInt(e);
            if(t >= 0) ++count;
            else{
                
                winterSub.add(count);
                --k;
                count = 0;
            }
        }
        if(k < 0){
            
            out.println(-1);
            out.flush();
            return;
        }
        if(winterSub.size() > 0){
            
            lastSub.add(count);
            winterSub.remove(0);
        }
        int change = 2 * (winterSub.size() + lastSub.size());
        int bd = lastSub.size() + 1;
        
        Collections.sort(winterSub);
        int res = change, j = 0;
        for(int i = 0; i < bd; ++i){
            
            count = change;
            t = k;
            for(j = 0; j < i; ++j){
                
                t -= lastSub.get(j);
                --count;
            }
            if(t < 0) break;
            for(int e : winterSub)
                if(t >= e){
                    
                    t -= e;
                    count -= 2;
                }
            res = res < count ? res : count;
        }
        out.println(res);
        out.flush();
    }
}
