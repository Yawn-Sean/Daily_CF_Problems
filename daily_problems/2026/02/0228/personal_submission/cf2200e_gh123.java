import java.util.Scanner;

public class cf2200e {
    static final int m=1000000;
    static int[]pr=new int[m+1];
    static int[]cnt=new int[m+1];
    public static void main(String[] args) {
        for (int i = 0; i <=m; i++) {
            pr[i]=i;
        }
        for (int i = 2; i <=m; i++) {
            if(pr[i]==i){
                for (int j = i; j <=m; j+=i) {
                    pr[j]=i;
                    cnt[j]++;
                }
            }
        }
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[]a=new int[n];
            for (int i = 0; i < n; i++) {
                a[i]=sc.nextInt();
            }
            if(isSorted(a)){
                System.out.println("Bob");
            }else{
                boolean flag=false;
                for (int i = 0; i < n; i++) {
                    if(cnt[a[i]]>1){
                        flag=true;
                    }
                    a[i]=pr[a[i]];
                }
                if(flag){
                    System.out.println("Alice");
                }else{
                    if(isSorted(a)){
                        System.out.println("Bob");
                    }else{
                        System.out.println("Alice");
                    }
                }
            }
        }
        sc.close();
    }
    static boolean isSorted(int[]a){
        for (int i = 1; i < a.length; i++) {
            if(a[i]<a[i-1]){
                return false;
            }
        }
        return true;
    }
}
