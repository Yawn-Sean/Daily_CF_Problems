//参考图解https://www.luogu.com.cn/article/yd8u3k4m
import java.io.*;

public class c1148 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int n,cnt;
    static int[] a= new int[1000001], b = new int[1000001];
    static int[][] ans = new int[1000002][4];
    static int abs(int u,int v){
        if(u>v) return u-v;
        else return v-u;
    }
    static void swap(int x,int y){
        int temp = y;
        y = x;
        x = temp;
    }
    static void get(int x,int y){
        b[a[x]]=y;
        b[a[y]]=x;
//        swap(a[x],a[y]);
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
        ans[++cnt][1] = x;
        ans[cnt][2] = y;
    }
    static void get1(int x,int y){//x>mid,y>mid
        get(1,x);
        get(1,y);
        get(1,x);
    }
    static void get2(int x,int y){//x<mid,y<mid
        get(y,n);
        get(x,n);
        get(y,n);
    }
    static void get3(int x,int y){//x<mid,y>mid但y-x<n/2
        get(1,y);
        get(x,n);
        get(1,n);
        get(1,y);
        get(x,n);
    }
    static void solve(int u,int v){
        if(u==v) return;
//        if(u>v) swap(u,v);
        if (u > v) {
            int temp = u;
            u = v;
            v = temp;
        }
        if(abs(u,v)*2>=n) get(u,v);
        else if(u*2>n) get1(u,v);
        else if(v*2<=n) get2(u,v);
        else get3(u,v);
    }
    public static void main(String[] args)throws Exception{
        n=nextInt();
        for(int i=1;i<=n;i++){
            a[i]=nextInt();
            b[a[i]] = i;
        }
        for(int i=1;i<=n;i++){
            solve(i,b[i]);
        }
        pw.println(cnt);
        for(int i=1;i<=cnt;i++){
            pw.println(ans[i][1]+" "+ans[i][2]);
        }
        pw.flush();
    }
}
