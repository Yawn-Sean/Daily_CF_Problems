https://codeforces.com/problemset/submission/1609/260214621
import java.util.Arrays;
import java.util.Scanner;
public class D1609 {
    static int n,m;
    static int[]p,s,sz;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        p=new int[1010];
        s=new int[1010];
        sz=new int[1010];
        m=sc.nextInt();
        for (int i = 1; i <=n; i++) {
            p[i]=i;
            s[i]=1;
        }//初始化
        int cnt=0;
        while (m-->0) {
            int x=sc.nextInt();
            int y=sc.nextInt();
            int px=find(x);
            int py=find(y);
            if(px!=py){
                s[py]+=s[px];
                p[px]=py;
            }else{
                cnt++;
            }//union
            int k=0;
            for (int i = 1; i <=n; i++) {
                if(find(i)==i) sz[k++]=s[i];
            }
            Arrays.sort(sz,0,k);
            int sum=0;
            for (int i = 0; i <k&&i<cnt+1; i++) {
                sum+=sz[k-1-i];
            }
            System.out.println(sum-1);
        }
        sc.close();
    }
 
    
    public static int find(int k){
        if(p[k]==k){
            return k;
        }else{
            p[k]=find(p[k]);
            return p[k];
        }
    }
}
