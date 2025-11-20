import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class E104536 {
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]nums1=new int[n];
        int[]nums2=new int[n];
        for (int i = 0; i < n; i++) {
            nums1[i]=sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            nums2[i]=sc.nextInt();
        }
       sc.close();
       List<Integer>vals=new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if(nums1[i]>nums2[i]){
                vals.add(nums1[i]);
                vals.add(nums2[i]);
            }else{
                vals.add(nums2[i]);
                vals.add(nums1[i]);
            }
        }
        List<Integer>cur=new ArrayList<>();
        for (int x : vals) {
            int pt=lower(cur,x);
            if(pt==-1||pt==cur.size()){
                cur.add(x);
            }else{
                cur.set(pt, x);
            }
        }
        System.out.println(cur.size());
    }
    static int lower(List<Integer>list,int target){
       int left = 0, right = list.size()-1;
       int ans=-1;
        while (left <=right) {
            int mid = (left + right) / 2;
            if (list.get(mid) >= target) {
                ans=mid;
                right = mid - 1;
            } else {
                left=mid+1;
            }
        }
        return ans;
    }
}
