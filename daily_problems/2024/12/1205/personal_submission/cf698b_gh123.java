//https://codeforces.com/problemset/submission/698/294883303
import java.util.Arrays;
import java.util.Scanner;

public class B698 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]nums=new int[n];
        for (int i = 0; i < nums.length; i++) {
            nums[i]=sc.nextInt()-1;
        }
        int res=-1;
        for (int i = 0; i < n; i++) {
            if(nums[i]==i){
                res=i;
            }
        }
        sc.close();
        int[]vis=new int[n];
        int ans=0;
        Arrays.fill(vis, -1);
        for (int i = 0; i < n; i++) {
            if(vis[i]==-1){
                int u=i;
                while (vis[u]==-1) {
                    vis[u]=i;
                    u=nums[u];
                }
                if(vis[u]==i&&u!=res){
                    ans++;
                    if(res>=0){
                        nums[u]=res;
                    }else{
                        nums[u]=u;
                        res=u;
                    }
                }
              
            }
           
        }
        System.out.println(ans);
        for (int i = 0; i < n; i++) {
            System.out.print(nums[i]+1+" ");
        }

    }
}
