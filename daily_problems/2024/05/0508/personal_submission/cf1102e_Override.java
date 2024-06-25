//合并区间 https://leetcode.cn/problems/merge-intervals/description/
import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class e1102 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    //找几个不相交的线段
    static int mod = 998244353;
    static int n;
    static int[] a = new int[200001];
    static Map<Integer,Integer> r = new HashMap<>();//a[i]最后的位置

    public static void main(String[] args)throws Exception{
        n = nextInt();
        for(int i=1;i<=n;i++){
            a[i] = nextInt();
        }
        for(int i=n;i>=1;i--){
            if(r.get(a[i]) != null){
                continue;
            }
            r.put(a[i],i);
        }
        int temp=1,last=1,ans=0;
        while (temp<=n){
            for(;temp<=last&&last<=n;temp++){   //贪心合并
                if(last<r.get(a[temp])){
                    last = r.get(a[temp]);
                }
//                System.out.println("temp="+temp+"last="+last);
            }
            ans++;
            last++;
            if(last>n) break;
        }
//        System.out.println(ans);
        //快速幂  初始为0 只有一种状态
        pw.println((ksm(2,ans-1)+mod)%mod);
        pw.flush();
    }
    static long ksm(long a,long b){//静态全局变量就不用传参
        long s=1;
        while (b!=0){
            if((b&1)!=0){
                s=s*a%mod;
            }
            a=a*a%mod;
            b>>=1;
        }
        return s;
    }

}
