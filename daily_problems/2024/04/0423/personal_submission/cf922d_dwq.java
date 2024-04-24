import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        long[] hcount = new long[n];
        long[] scount = new long[n];
        String[] strs = new String[n];
        Integer[] idxs = new Integer[n];
        long t = n, h = 0, s = 0;
        int i = -1;
        String str = null;
        while(--t > -1){
            str = in.readLine();
            strs[++i] = str;
            h = 0;
            s = 0;
            for(char c : str.toCharArray()){
                
                if(c == 'h') ++h;
                else if(c == 's') ++s;
            }
            hcount[i] = h;
            scount[i] = s;
            idxs[i] = i;
        }
        
        Arrays.sort(idxs, (a,b)->Long.compare(hcount[a] * scount[b], scount[a] * hcount[b]));
        long res = 0;
        t = 0;
        for(int idx : idxs){
            
            for(char c : strs[idx].toCharArray())
                if(c == 's') ++t;
                else res += t;
        }
        out.print(res);
        out.flush();
    }
}
