import java.util.Scanner;

public class B780 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]point=new int[n];
        int[]speed=new int[n];
        for (int i = 0; i < n; i++) {
            point[i]=sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            speed[i]=sc.nextInt();
        }
        double left=0,right=1e+9;
        while (right-left>0.0000001) {
            double mid=(right+left)/2;
            double min=0, max=1e+9;
            for (int i = 0; i < n; i++) {
                min=Math.max(point[i]-speed[i]*mid, min);
                max=Math.min(point[i]+speed[i]*mid, max);
            }
            if(max>min) right=mid;
            else left=mid;
        }
        System.out.println(right);
    }
    
}
