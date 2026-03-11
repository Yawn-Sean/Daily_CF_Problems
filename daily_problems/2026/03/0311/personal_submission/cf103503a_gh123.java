import java.util.Arrays;
import java.util.Scanner;

public class cf103503a {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long s=sc.nextLong();
        long[]nums=new long[n];
        long cur=0;
        for (int i = 0; i < n; i++) {
            nums[i]=sc.nextLong();
            cur+=nums[i];
        }
        Arrays.sort(nums);
        long[]pre=new long[n+1];
        for (int i = 0; i < n; i++) {
            pre[i+1]=pre[i]+nums[i];
        }
        long l=0,r=(long)2e9;
        long ans=-1;
        while (l<=r) {
            long mid=(r-l)/2+l;
            int pos=lower(nums,mid);
            if(cur+(mid+1)*mid/2-pre[pos]>=s){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int pos=lower(nums,ans);
        System.out.println(ans-pos+n);
        sc.close();
    }
    static int lower(long[]arr,long tar){
        int l=0,r=arr.length-1;
        int ans=r;
        while (l<=r) {
            int mid=(r-l)/2+l;
            if(arr[mid]>=tar){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
}
