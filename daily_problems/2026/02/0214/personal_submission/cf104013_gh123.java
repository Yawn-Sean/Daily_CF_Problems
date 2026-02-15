import java.util.Scanner;
//今天情人节了。。。
public class cf104013 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <=n; j++) {
                if(!query(sc, j-1, j)){
                    return;
                }
            }
            for (int j = n; j >=2; j--) {
                if(!query(sc, j-1, j)){
                    return ;
                }
            }
        }   
        sc.close();
    }
    static boolean query(Scanner sc,int x,int y){
        System.out.println(x+" "+y);
        System.out.flush();
        if(sc.hasNext()){
            String s=sc.next();
            if(s.equals("WIN")){
                System.exit(0);
                return false;
            }
        }
        return true;
    }
}
