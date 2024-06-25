import java.io.*;

public class a1168 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int N = 500005,n,m;
    static int[] a = new int[N];
    static int[] w = new int[N];
    static boolean check(int x){
        for(int i=1;i<=n;i++) a[i]=w[i];
        for(int i=1;i<=n;i++){
            if(a[i]<a[i-1]){
                if(a[i-1]-a[i]>x) return false;
                a[i]=a[i-1];
            }else{
                if(a[i-1]+m-a[i]<=x) a[i]=a[i-1];
            }
        }
        return true;
    }

    public static void main(String[] args)throws Exception{
        n = nextInt();
        m = nextInt();
        for(int i=1;i<=n;i++){
            w[i]=nextInt();
        }
        int l=0,r=m,mid;
        while (l<r){
            mid = (l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        pw.print(l);
        pw.flush();
    }
}
