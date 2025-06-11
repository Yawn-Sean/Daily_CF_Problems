
import java.io.*;

//ai-1 ai+1 都在b数组 想要加入ai  删除哪一个都不行 所以方案数为0
//ai-1 ai+1 只有一个在b数组，删除掉不在b数组那一个  方案数为1
//ai-1 ai+1 都不在b数组 方案数有两个
public class b1442 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static long nextLong()throws  Exception{
        cin.nextToken();
        return (long) cin.nval;
    }
    static int maxn = 200000+50;
    static int mod = 998244353;
    static long[] a = new long[maxn];
    static long[] b = new long[maxn];
    static long[] pos = new long[maxn];
    static long T,n,m;
    static long[] vis = new long[maxn];
    public static void main(String[] args)throws Exception{
        T = nextInt();
        while (T-->0){
            n = nextInt();
            m = nextInt();
            for(int i=1;i<=n;i++){
                a[i] = nextInt();
                pos[(int)a[i]] = i;
                vis[(int)a[i]] = 0;
            }
            for(int i=1;i<=m;i++){
                b[i] = nextInt();
                vis[(int)b[i]] = 1;
            }
            long ans = 1;
            for(int i=1;i<=m;i++){
                long cnt = 0;
                vis[(int) b[i]] = 0;
                if(pos[(int) b[i]]-1 >= 1 && vis[(int)a[(int)pos[(int)b[i]]-1]] ==0){
                    cnt++;
                }
                if(pos[(int) b[i]]+1 <= n && vis[(int)a[(int)pos[(int)b[i]]+1]] ==0){
                    cnt++;
                }
                ans = (ans*cnt) % mod;//乘法原理
            }
            pw.println(ans);

        }
        pw.flush();
    }

}
