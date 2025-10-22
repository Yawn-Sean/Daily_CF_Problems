import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class K105582 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        List<int[]>pts=new ArrayList<>();
        if(n%2==1){
            pts.add(new int[]{0,0});
            int x=0,y=0;
            for (int i = 0; i < n/2-1; i++) {
                y+=25;
                pts.add(new int[]{x,y});
                x+=25;
                pts.add(new int[]{x,y});
            }
            x=Math.max(x, 25);
            pts.add(new int[]{x,0});
            pts.add(new int[]{x/25*9,-x/25*12});
        }else{
            pts.add(new int[]{0,0});
            int x=0,y=0;
            for (int i = 0; i < n/2-1; i++) {
                y+=25;
                pts.add(new int[]{x,y});
                x+=25;
                pts.add(new int[]{x,y});
            }
            pts.add(new int[]{x,0});
        }
        sc.close();
        int dx=5,dy=12;
        for (int[] a : pts) {
            System.out.println(a[0]*dx+a[1]*dy+" "+(a[0]*(-dy)+a[1]*dx));
        }
    }
}
