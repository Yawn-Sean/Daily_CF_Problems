//https://codeforces.com/problemset/submission/924/304501276
import java.util.Scanner;

public class C924 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]nums=new int[n];
        long ans=0;
        for (int i = 0; i < n; i++) {
            nums[i]=sc.nextInt();
            ans-=nums[i];
        }
        for (int i = n-2; i >=0; i--) {
            nums[i]=Math.max(nums[i], nums[i+1]-1);
        }
        for (int i = 1; i < n; i++) {
            nums[i]=Math.max(nums[i-1], nums[i]);
            ans+=nums[i];
        }
        System.out.println(ans);
        sc.close();
    }
}
