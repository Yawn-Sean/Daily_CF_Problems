//对于min-max之间的数字插入是没有影响，因为最后总会插入1和x，所以最后最后只需要考虑1和x
//查看是否考虑1和x，遍历求影响较小的值，score只会增加
//记得开long
import java.io.*;

public class d1671 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int[] a= new int[200010];
    public static void main(String[] agrs)throws Exception{
        int t = nextInt();
        while(t-->0){
            int n = nextInt();
            int x = nextInt();
            int minn = Integer.MAX_VALUE;
            int maxn = Integer.MIN_VALUE;
            long ans  = 0;
            for(int i=1;i<=n;i++){
                a[i]=nextInt();
                minn = Math.min(minn,a[i]);
                maxn = Math.max(maxn,a[i]);
            }
            for(int i=1;i<=n-1;i++){
                ans+=Math.abs(a[i+1]-a[i]);
            }
            if(minn>1){ //1的影响
                int res1 = Math.min(a[1]-1,a[n]-1);
                for(int i=2;i<=n;i++){
                    res1 = Math.min(res1,a[i]-1+a[i-1]-1-Math.abs(a[i]-a[i-1]));
                }
                ans+=res1;
            }
            if(x>maxn){//x的影响
                int res2 = Math.min(x-a[1],x-a[n]);
                for(int i=2;i<=n;i++){
                    res2 = Math.min(res2,x-a[i]+x-a[i-1]-Math.abs(a[i]-a[i-1]));
                }
                ans+=res2;
            }
            pw.println(ans);
        }
        pw.flush();
    }
}
