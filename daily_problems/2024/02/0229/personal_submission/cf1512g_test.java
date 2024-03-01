import java.util.Scanner;

public class G1512 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        int[]d=new int[(int)1e7+5];
        long[]ans=new long[(int)1e7+5];
        for (int i = 1; i <=1e+7; i++) {
            for (int j = i; j <=1e+7; j+=i) {
                d[j]+=i;
            }
        }
        for (int i = 1; i <=1e7; i++) {
            if(d[i]<=1e7&&ans[d[i]]==0){
                ans[d[i]]=i;
            }
        }
        while (t-->0) {
            int c=sc.nextInt();
            if(ans[c]!=0){
                System.out.println(ans[c]);
            }else{
                System.out.println(-1);
            }
        }
        sc.close();
    }
}
