import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.List;
public class cf102788k {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt();
        List<String>list=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String s=sc.next();
            char source='A';
            char tmp='C';
            char target='B';
            StringBuilder sb=new StringBuilder();
            for (int j = n-1; j >=0; j--) {
                if(s.charAt(j)==target){
                    sb.append('1');
                    char temp=source;
                    source=tmp;
                    tmp=temp;
                }else{
                    sb.append('0');
                    char temp=tmp;
                    tmp=target;
                    target=temp;
                }
            }
            list.add(sb.toString());
        }
        String max=Collections.max(list);
        int maxid=list.indexOf(max);
        System.out.println(maxid+1);
        sc.close();
    }

}
