import java.util.Scanner;

public class D104064 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        final int inf=(int)1e9;
        int addmax=-inf;
        int addmin=inf;
        int minusmax=-inf;
        int minusmin=inf;
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            int y=sc.nextInt();
            addmax=Math.max(addmax, x+y);
            addmin=Math.min(addmin, x+y);
            minusmax=Math.max(minusmax, x-y);
            minusmin=Math.min(minusmin, x-y);
        }
        if(addmax==addmin&&minusmax==minusmin){
            System.out.println(4);
        }else if(addmax==addmin||minusmax==minusmin){
            System.out.println(addmax-addmin+minusmax-minusmin+5);
        }else{
            System.out.println(addmax-addmin+minusmax-minusmin+4);
        }
        sc.close();
    }    
}
