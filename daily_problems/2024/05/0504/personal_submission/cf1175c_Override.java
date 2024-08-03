
import java.io.*;

public class c1175 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int t,n,k,ans,pos;
    static int maxn = 200009;
    static int[] a = new int[maxn];

    public static void main(String[] args) throws Exception{
        t = nextInt();
        while (t--!=0){
            n=nextInt();
            k=nextInt();
            for(int i=1;i<=n;i++) a[i]=nextInt();
            ans=1000000001;pos=0;
            for(int i=1;i<=n-k;i++){
                if(ans>a[i+k]-a[i]){
                    ans=a[i+k]-a[i];
                    pos=a[i]+ans/2;
                }
            }
            pw.println(pos);
            pw.flush();
        }
    }
}
