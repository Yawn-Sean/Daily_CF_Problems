//https://codeforces.com/problemset/submission/848/296425313
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A848 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.close();
        List<Integer>list=new ArrayList<>();
        for (int i = 1000; i >1; i--) {
            while (n>=i*(i-1)/2) {
                n-=i*(i-1)/2;
                list.add(i) ;
            }
        }
        if(list.size()>0){
            for (int i = 0; i < list.size(); i++) {
                int k=list.get(i);
                while (k-->0) {
                    System.out.print((char)('a'+i));
                }
            }
            System.out.println();
        }else{
            System.out.println('a');
        }

    }
}
