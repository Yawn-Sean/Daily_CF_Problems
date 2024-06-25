import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class cf1148C {
    static int[] p,a;
    static List<Pair> ans;
    static int n;
    static void swap(int x,int y){
        int temp=a[x];
        a[x]=a[y];
        a[y]=temp;
        p[a[x]]=x;
        p[a[y]]=y;
        ans.add(new Pair(x,y));
    }
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        n= scan.nextInt();
        a=new int[n+1];
        p=new int[n+1];
        ans=new ArrayList<>();
        for(int i=1;i<=n;i++){
            a[i]= scan.nextInt();
            p[a[i]]=i;
        }
        for(int i=1;i<=n/2;i++){
            if(p[i]!=i){
                if(p[i]<=n/2){
                    swap(p[i],n);
                    swap(i,n);
                }else{
                    swap(1,p[i]);
                    swap(1,n);
                    swap(i,n);
                }
            }
        }
        for(int i=n/2+1;i<=n;i++){
            if(p[i]!=i){
                if(p[i]>n/2){
                    swap(1,p[i]);
                    swap(1,i);
                }else{
                    swap(p[i],n);
                    swap(1,n);
                    swap(1,i);
                }
            }
        }
        if(a[1]!=1) swap(1,n);
        System.out.println(ans.size());
        for(Pair as:ans){
            System.out.println(as.frist+" "+as.second);
        }
    }
}
class Pair{
    int frist,second;
    Pair(int frist, int second){
        this.frist=frist;
        this.second=second;
    }
}
