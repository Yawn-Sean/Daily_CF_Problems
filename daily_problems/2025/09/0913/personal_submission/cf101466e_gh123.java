
import java.util.Scanner;

public class E101466 {
    static int[]prefix(String s){
        int n=s.length();
        int[]pre=new int[n];
        int j=0;
        for (int i = 1; i < n; i++) {
            while (j>0&&s.charAt(j)!=s.charAt(i)) {
                j=pre[j-1];
            }
            if(s.charAt(j)==s.charAt(i)){
                j++;
            }
            pre[i]=j;
        }
        return pre;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        String t=sc.nextLine();
        int cur=sc.nextInt();
        int tn=t.length();
        sc.close();
        int l=1,r=tn;
        int ans=-1;
        while (l<=r) {
            int mid=(l+r)/2;
            String tmp=t.substring(0, mid)+"#"+s;
            int[]pre=prefix(tmp);
            int cnt=0;
            for (int i : pre) {
                if(i==mid){
                    cnt++;
                }
            }
            if(cnt>=cur){
                l=mid+1;
                ans=mid;
            }else{
                
                r=mid-1;
            }
        }
        if(ans>0){
            System.out.println(t.substring(0, ans));
        }else{
            System.out.println("IMPOSSIBLE");
        }
    }
}
