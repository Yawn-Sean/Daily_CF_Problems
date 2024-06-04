//使用map消消乐，但直接这样有点存疑
//另一个方法是用优先队列堆去模拟
import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class d962 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static long nextInt()throws  Exception{
        cin.nextToken();
        return (long) cin.nval;
    }
    static Long[] a = new Long[200001];
    public static void main(String[] args)throws Exception{
        int n = (int)nextInt();
        int s = n;
        Map<Long,Integer> mp = new HashMap<>();
        for(int i=1;i<=n;i++){
            a[i] = nextInt();
            if(mp.get(a[i]) != null && mp.get(a[i])>0){
                while (mp.get(a[i]) !=null && mp.get(a[i])>0){
                    int index = mp.get(a[i]);
                    a[index]=(long)0;s--;mp.put(a[i],0);
                    a[i]=2*a[i];
                }
                mp.put(a[i],i);
            }else{
                mp.put(a[i],i);
            }
        }
        pw.println(s);
        for(int i=1;i<=n;i++){
            if(a[i]>0) pw.print(a[i]+" ");
        }
        pw.flush();
    }
}
