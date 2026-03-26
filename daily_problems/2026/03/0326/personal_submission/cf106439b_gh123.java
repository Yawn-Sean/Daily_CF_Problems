import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class cf106439b {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        int[]save={1,3,5,2,4};
        while (t-->0) {
            int n=sc.nextInt();
            if(n==2||n==3){
                System.out.println(-1);
            }else{
                List<Integer>list=new ArrayList<>();
                int group=n/5;
                for (int x = 0; x < group; x++) {
                    for (int i = 0; i < 5; i++) {
                        list.add(x*5+save[i]);
                    }
                }
                int rem=n%5;
                if(rem==1){
                    list.add(n);
                }else if(rem==2){
                    list.set(list.size()-1,n);
                    list.add(n-3);
                    list.add(n-1);
                }else if(rem==3){
                    list.set(list.size()-1,n-1);
                    list.add(n-4);
                    list.add(n-2);
                    list.add(n);
                }else if(rem==4){
                    list.add(n-2);
                    list.add(n);
                    list.add(n-3);
                    list.add(n-1);
                }
                StringBuilder sb=new StringBuilder();
                for (int i = 0; i < list.size(); i++) {
                    sb.append(list.get(i));
                    if(i<list.size()-1){
                        sb.append(" ");
                    }
                }
                System.out.println(sb.toString());
            }
        }
        sc.close();
    }
}
