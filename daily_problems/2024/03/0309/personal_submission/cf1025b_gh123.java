import java.util.HashSet;
import java.util.Scanner;

public class B1025 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][]ar=new int[n][2];
        for (int i = 0; i < n; i++) {
            ar[i][0]=sc.nextInt();
            ar[i][1]=sc.nextInt();
        }
        HashSet<Integer>set=new HashSet<>();
        add_divide(set, ar[0][0]);
        add_divide(set, ar[0][1]);
        int isok=0;
        for (int k : set) {
            int cnt=0;
            for (int i = 0; i < n; i++) {
                if(ar[i][0]%k==0||ar[i][1]%k==0){
                    cnt++;
                }
            }
            if(cnt==n){
                System.out.println(k);
                isok++;
                break;
            }
        }
        if(isok==0){
            System.out.println(-1);
        }
        sc.close();
    }
    public static void add_divide(HashSet<Integer>set,int m){
        for (int i = 2; i*i <=m; i++) {
            if(m%i==0){
                set.add(i);
            }
            while (m%i==0) {
                m=m/i;
            }
        }
        if(m>1){
            set.add(m);
        }
    }
}
