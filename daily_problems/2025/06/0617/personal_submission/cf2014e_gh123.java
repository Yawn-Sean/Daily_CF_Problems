//https://codeforces.com/problemset/submission/2114/324704829
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class E2114 {
    static int[]a;
    //看题解跟大佬的代码都理解，自己做的话，肯定做不出来，知道笨，就是不知道笨在哪了。。。
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
        a=new int[n+1];
        long[][]ans=new long[n+1][2];
        for (int i = 1; i <=n; i++) {
            a[i]=sc.nextInt();
        }
        ArrayList<ArrayList<Integer>>arr=new ArrayList<>();
        for (int i = 0; i < n+1; i++) {
            arr.add(new ArrayList<>());
        }
        for (int i = 1; i < n; i++) {
            int u=sc.nextInt();
            int v=sc.nextInt();
            arr.get(u).add(v);
            arr.get(v).add(u);
        }
       
        ans[0][0]=0;
        ans[0][1]=a[1];
        dfs(0,1,arr,ans);
        for (int i = 1; i <=n; i++) {
            System.out.print(ans[i][1]+" ");
        }
        System.out.println();
        }
         sc.close();
        
    }
    static void dfs(int fa,int cur,ArrayList<ArrayList<Integer>>arr,long[][]ans){
        ans[cur][1]=Math.max(-ans[fa][0]+a[cur], a[cur]);
        ans[cur][0]=Math.min(-ans[fa][1]+a[cur], a[cur]);
        for (int i = 0; i < arr.get(cur).size(); i++) {
            int tem=arr.get(cur).get(i);
            if(tem!=fa){
                dfs(cur, tem, arr, ans);
            }
        }
        return;
    }
    public int minimumCoins(int[]arr,int k){
       Arrays.sort(arr);
      int n=arr.length;
      int[]pre=new int[n+1];
      int sum=0;
      for (int i = 1; i < pre.length; i++) {
        pre[i]=pre[i-1]+arr[i-1];
        sum+=arr[i-1];
      }
      int max=0;
      for (int i = 0; i < n; i++) {
        if(i>0&&arr[i]==arr[i-1]){
            continue;
        }
        int idx=upper(arr,arr[i]+k,i,n-1);
        int tem=pre[idx+1]-pre[i]+(n-1-idx)*(arr[i]+k);
        max=Math.max(max, tem);
      }
      return sum-max;
    }
    public static int upper(int[]arr,int x,int l,int r){
        int ans=-1;
        while (l<=r) {
            int mid=(l+r)/2;
            if(arr[mid]>x){
                r=mid-1;
            }else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
}
