//https://codeforces.com/problemset/submission/231/300457967    
import java.util.Scanner;

public class D231 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt();
        int y=sc.nextInt();
        int z=sc.nextInt();
        int xx=sc.nextInt();
        int yy=sc.nextInt();
        int zz=sc.nextInt();
        int[]a=new int[6];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        int ans=0;
        if(y<0){
            ans+=a[0];
        }
        if(y>yy){
            ans+=a[1];
        }
        if(z<0){
            ans+=a[2];
        }
        if(z>zz){
            ans+=a[3];
        }
        if(x<0){
            ans+=a[4];
        }
        if(x>xx){
            ans+=a[5];
        }
        System.out.println(ans);
        sc.close();
    }
}
