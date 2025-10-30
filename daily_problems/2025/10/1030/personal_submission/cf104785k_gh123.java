import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class K104785 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        List<Integer>lista=new ArrayList<>();
        List<Integer>listb=new ArrayList<>();
        for (int i = 1; i <=m; i++) {
            int x=sc.nextInt();
            int y=sc.nextInt();
            if(x<y){
                lista.add(i);
            }else{
                listb.add(i);
            }
        }
        System.out.println("YES");
        if(lista.size()>listb.size()){
            System.out.println(lista.size());
            for (int i = 0; i < lista.size(); i++) {
                System.out.print(lista.get(i)+" ");
            }
        }else{
            System.out.println(listb.size());
            for (int i = 0; i < listb.size(); i++) {
                System.out.print(listb.get(i)+" ");
            }
        }
        sc.close();
    }
}
