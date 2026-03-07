import java.util.Scanner;

public class cf102465e{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String[]names=new String[n];
        int[]score=new int[n];
        int[]other=new int[n];  
        long total=0;
        long total_other=0;
        for (int i = 0; i < n; i++) {
            names[i]=sc.next();
            int y=sc.nextInt();
            if(y==0){
                score[i]=0;
                other[i]=49;
            }else if(y==100){
                score[i]=9950;
                other[i]=50;
            }else{
                score[i]=y*100-50;
                other[i]=99;
            }
            total+=score[i];
            total_other+=other[i];
        } 
        if(total>10000||total+total_other<10000){
            System.out.println("IMPOSSIBLE");
        }else{
            long resid=10000-total;
            for (int i = 0; i < n; i++) {
                 long mi = score[i] + Math.max(0, resid - (total_other - other[i]));
                  long ma = score[i] + Math.min(other[i], resid);
                    System.out.printf("%s %d.%02d %d.%02d\n", 
                    names[i], mi / 100, mi % 100, ma / 100, ma % 100);
            }
        }
        sc.close();
    }
}
