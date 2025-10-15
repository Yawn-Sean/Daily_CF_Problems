//https://codeforces.com/problemset/submission/818/320866201
//(num[i]-nums[i-1]+n-1)%n+1 这个好，不然就得再条件判断一次了，
import java.util.Arrays;
import java.util.Scanner;

public class B818 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]nums=new int[m];
        for (int i = 0; i < m; i++) {
            nums[i]=sc.nextInt()-1;
        }
        int[]vis=new int[n+1];
        int[]ans=new int[n];
        sc.close();
        Arrays.fill(vis, -1);
        Arrays.fill(ans, -1);
        for (int i = 1; i < m; i++) {
            int p=nums[i-1];
            int step=(nums[i]-nums[i-1]+n-1)%n+1;
            if(vis[step]!=-1&&vis[step]!=p){
                System.out.println(-1);
                return;
            }
            if(ans[p]!=-1&&ans[p]!=step){
                System.out.println(-1);
                return;
            }
            vis[step]=p;
            ans[p]=step;
        }
        int x=1;
        for (int i = 0; i < n; i++) {
            if(ans[i]==-1){
                while (vis[x]!=-1) {
                    x++;
                }
                ans[i]=x;
                vis[x]=i;
            }
        }
        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i]+" ");
        }
    }
}
