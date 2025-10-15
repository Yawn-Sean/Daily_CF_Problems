
import java.util.Scanner;

public class cf317a_micheal {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long x=sc.nextLong();
        long y=sc.nextLong();
        long m=sc.nextLong();
        sc.close();
        if(x>=m||y>=m){
            System.out.println(0);
            return;
        }
        if(x<=0&&y<=0){
            System.out.println(-1);
            return;
        }
        long ans=0;
        if(x<=0){
            ans+=(-x+y-1)/y;
            x+=ans*y;
        }
        if(y<=0){
            ans+=(-y+x-1)/x;
            y+=ans*x;
        }
        long tmp=0;
        while(x<m&&y<m){
            if(x>y){
                tmp=x;
                x=y;
                y=tmp;
            }
            x+=y;
            ans++;
        }
        System.out.println(ans);
    }
}
