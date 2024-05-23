import java.io.*;
import java.util.ArrayList;

public class c1132 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    public static void main(String[] args)throws Exception{
        int n = nextInt();
        int q = nextInt();
        int[] cur = new int[n+1];
        ArrayList<Integer> ls = new ArrayList<>();
        ArrayList<Integer> rs = new ArrayList<>();
        for (int i=0;i<q;i++){
            int l = nextInt();
            int r = nextInt();
            ls.add(l);
            rs.add(r);
            for (int j=l;j<=r;j++){
                cur[j]+=1;
            }
        }
        int[] acc = new int[n+2];
        int ans = 0;
        for(int i=0;i<q;i++){
            int l = ls.get(i);
            int r = rs.get(i);
            for(int j=l;j<=r;j++){
                cur[j]-=1;
            }

            int cnt = 0;
            for(int j=1;j<=n;j++){
                acc[j+1] = acc[j];
                if(cur[j]>=1) cnt+=1;
                if(cur[j]==1) acc[j+1]+=1;
            }
            for(int j=0;j<i;j++){
                ans = Math.max(ans,cnt-(acc[rs.get(j)+1]-acc[ls.get(j)]));
            }
            for(int j=l;j<=r;j++){
                cur[j]+=1;
            }
        }

        pw.print(ans);
        pw.flush();
    }
}
