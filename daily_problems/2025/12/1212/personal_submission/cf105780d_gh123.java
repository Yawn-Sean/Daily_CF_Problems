import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class D105780 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        List<long[]>pts=new ArrayList<>();
        int n=sc.nextInt();
        Set<String>set=new HashSet<>();
        for (int i = 0; i < n; i++) {
            long x=sc.nextLong();
            long y=sc.nextLong();
            pts.add(new long[]{x,y});
            String s=x+"_"+y;
            set.add(s);
        }
        sc.close();
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long x1=pts.get(i)[0];
                long y1=pts.get(i)[1];
                long x2=pts.get(j)[0];
                long y2=pts.get(j)[1];
                long dx=x2-x1;
                long dy=y2-y1;
                long[]p1={x1+dx-dy,y1+dx+dy};
                long[]p2={x1-dy,y1+dx};
                String s1=p1[0]+"_"+p1[1];
                String s2=p2[0]+"_"+p2[1];
                if(set.contains(s1)&&set.contains(s2)){
                    ans++;
                }
                long[]p3={x1+dy,y1-dx};
                long[]p4={x1+dx+dy,y1+dy-dx};
                String s3=p3[0]+"_"+p3[1];
                String s4=p4[0]+"_"+p4[1];
                if(set.contains(s3)&&set.contains(s4)){
                    ans++;
                }
            }
        }
        System.out.println(ans/4);
    }

}
