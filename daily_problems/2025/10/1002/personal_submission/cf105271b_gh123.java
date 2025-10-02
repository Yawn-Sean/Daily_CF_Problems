import java.util.Scanner;

public class B105271 {
    static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        int n=sc.nextInt();
        int[]a=new int[n];
        int cur=1;
        for (int i = 0; i < n; i++) {
            while (check(i,cur)) {
                cur++;
            }
            a[i]=cur;
        }
        System.out.print("! ");   
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }
    static boolean check(int i,int cur){
        System.out.println("? "+(i+1)+" "+cur);
        char c=sc.next().charAt(0);
        if(c=='<'){
            return true;
        }
        return false;
        // sc.close();
    }
}
