import java.util.Scanner;

public class cf104574e {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int[]a=new int[52];
        for (int i = 0; i < 52; i++) {
            a[i]=sc.nextInt();
        }   
        for (int step = 0; step < 8; step++) {
            int[]tem=new int[52];
            int idx=0;
            for (int i = 0; i < 26; i++) {
                tem[idx]=a[i];
                tem[idx+1]=a[i+26];
                idx+=2;
            }
            a=tem;
            boolean flag=true;
            for (int k = 26; k <52; k++) {
                if(a[k]==1){
                    flag=false;
                    break;
                }
            }
            if(flag){
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
        sc.close();
    }
}
