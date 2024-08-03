import java.io.*;
import java.util.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int caseCount = Integer.parseInt(in.readLine());
        int n = 0, t = 0, i = 0, m = 0;
        int min = 0, res = 0, count = 0, div = 0;
        boolean flag = false;
        int[] arr = null, cate = null;
        String s = null;
        String[] strs = null;
        while(--caseCount > -1){
            
            n = Integer.parseInt(in.readLine());
            m = 0;
            arr = new int[n];
            s = in.readLine();
            strs = s.split(" ");
            i = -1;
            for(String e : strs){
                
                t = Integer.parseInt(e) - 1;
                if(++arr[t] == 1) ++m;
            }
            cate = new int[m];
            min = Integer.MAX_VALUE;
            i = -1;
            for(int e : arr){
                
                if(e > 0){
                    
                    cate[++i] = e;
                    min = min < e ? min : e;
                }
            }
            res = n;
            for(i = 1; i <= min; ++i){
                
                flag = false;
                count = 0;
                for(int e : cate){
                    
                    div = (e - 1) / (i + 1) + 1;
                    count += div;
                    if(div * i  > e){
                        
                        flag = true;
                        break;
                    }
                }
                if(!flag) res = res < count ? res : count;
            }
            out.println(res);
        }
        out.flush();
    }
}
