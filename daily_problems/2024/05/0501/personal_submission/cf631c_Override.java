
import java.io.*;
import java.util.Arrays;

public class c631 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int n,q,maxx;
    static int[] a = new int[200010];
    static int[] ans = new int[200010];
    static int[] id = new int[200010];
    static int[] op = new int[200010];

    public static void main(String[] args)throws Exception{
        n = nextInt();
        q = nextInt();
        for(int i=1;i<=n;i++) a[i]=nextInt();
        for(int i=1,opt,r;i<=q;i++){
            opt = nextInt();
            r = nextInt();
            id[r] = i;
            op[r] = opt;
            maxx = Math.max(maxx,r);
        }
        Arrays.sort(a,1,maxx+1);
        int mq=0,now=0,dt=1,dw=maxx;
        for(int i=maxx;i>=1;i--){
            if(now<id[i]){
                now=id[i];
                mq=op[i];
            }
            if(mq==1) ans[i]=a[dw--];
            else ans[i]=a[dt++];
        }
        for (int i=1;i<=maxx;i++) pw.print(ans[i]+" ");
        for (int i=maxx+1;i<=n;i++) pw.print(a[i]+" ");
        pw.flush();
    }
}
