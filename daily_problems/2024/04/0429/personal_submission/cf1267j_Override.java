
import java.io.*;

public class j1267 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int t,n,mn,cnt;
    static int[] a = new int[2000002];
    static int[] p = new int[2000002];

    public static void main(String[] args)throws Exception{
        t = nextInt();
        while (t-- !=0 ){
            n = nextInt();
            mn = Integer.MAX_VALUE;
            cnt = 0;
            boolean ia = true;
            for (int i=1;i<=n;i++){
               int temp = nextInt();
               a[temp]++;
            }
            for(int i=1;i<=n;i++){
                if(a[i]!=0){
                    mn = Math.min(mn,a[i]);
                    p[++cnt]=a[i];
                    a[i]=0;
                }
            }
            int ans = 0;
            ++mn;
            while (true){
                ans = 0;
                ia = false;
                for(int i=1;i<=cnt;i++){
                    int tmp =(p[i]-1)/mn+1;
                    ans+=tmp;
                    if((mn-1)*tmp>p[i]){
                        ia=true;break;
                    }
                }
                if(!ia)break;
                --mn;
            }
            pw.println(ans);
            pw.flush();
        }
    }

}
