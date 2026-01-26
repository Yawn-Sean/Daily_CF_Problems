import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;
public class C105215 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt();
        int[]cnt=new int[n*m+1];
        for (int i = 0; i < n*m; i++) {
            int x=sc.nextInt();
            cnt[x]++;
        }   
        List<Integer>vals=new ArrayList<>();
        for (int i = 0; i <=n*m; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                vals.add(i);
            }
            if(i>0){
                cnt[i]+=cnt[i-1];
            }
        }
        sc.close();
        for (int step = 1; step <=n; step++) {
            int st=-1;
            int cur=step;
            StringBuilder sb=new StringBuilder();
            for (int i = 0; i < m; i++) {
                st+=cur;
                sb.append(vals.get(st)).append(" ");
                cur=Math.min(cur, st-cnt[vals.get(st)-1]+1);
            }
            System.out.println(sb.toString().trim());
        }
    }
}
