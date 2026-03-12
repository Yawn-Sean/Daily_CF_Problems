import java.util.Scanner;
//prime
public class cf105453e {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][]grid=new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j]=sc.nextInt();
            }
        }   
        int[]cur=new int[n];
        boolean[]vis=new boolean[n];
        for (int i = 0; i < n; i++) {
            cur[i]=grid[i][i];
        }
        sc.close();
        long ans=0;
        for (int i = 0; i < n; i++) {
            int choose=-1;
            for (int j = 0; j < n; j++) {
                if(!vis[j]&&(choose==-1||cur[j]<cur[choose])){
                    choose=j;
                }
            }
            if(choose==-1){
                break;
            }
            ans+=cur[choose];
            vis[choose]=true;
            for (int j = 0; j < n; j++) {
                cur[j]=Math.min(cur[j], grid[choose][j]);
            }
        }
        System.out.println(ans);
    }
}
/* 这个是并查集的做法。居然也过了。。
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class cf105453e_uf {
  public static void main(String[] args) throws IOException {
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    String line=br.readLine();
    int n=Integer.parseInt(line.trim());
    int[][]edges=new int[n*(n+1)/2][3];
    int cnt=0;
    for (int i = 0; i < n; i++) {
        StringTokenizer st=new StringTokenizer(br.readLine());
        for (int j = 0; j < n; j++) {
            int w=Integer.parseInt(st.nextToken());
            if(i<=j){
                edges[cnt][0]=i;
                edges[cnt][1]=(i==j)?n:j;
                edges[cnt][2]=w;
                cnt++;
            }
        }
    }
    Arrays.sort(edges,0,cnt,(a,b)->a[2]-b[2]);
    int[]pa=new int[n+1];
    for (int i = 0; i < pa.length; i++) {
        pa[i]=i;
    }
    long ans=0;
    int num=0;
    br.close();
    for (int i = 0; i < cnt; i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        int pu=find(pa, u);
        int pv=find(pa, v);
        if(pu!=pv){
            if(pu<pv){
                pa[pv]=pu;
            }else{
                pa[pu]=pv;
            }
            ans+=w;
            num++;
            if(num==n){
                break;
            }
        }
    }
    System.out.println(ans);
  }
  static int find(int[]pa,int x){
    if(pa[x]==x){
        return x;
    }
    return pa[x]=find(pa, pa[x]);
  }
}


*/
