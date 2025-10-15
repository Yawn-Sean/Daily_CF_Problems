//https://codeforces.com/problemset/submission/275/320577005
//比较笨，为啥我用01BFS就做错呢。。。
import java.util.Scanner;
 
public class B275 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        char[][]cs=new char[n][m];
        for (int i = 0; i < n; i++) {
            cs[i]=sc.next().toCharArray();
        }   
        sc.close();
        boolean flag=true;
        for (int i = 0; i < n; i++) {
            char c='W';
            int cnt=1;
            for (int j = 0; j < m; j++) {
                if(cs[i][j]!=c){
                    c=cs[i][j];
                    cnt++;
                }
            }
            if(cnt>=4){
                flag=false;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            char c='W';
            int cnt=1;
            for (int j = 0; j < n; j++) {
                if(cs[j][i]!=c){
                    c=cs[j][i];
                    cnt++;
                }
            }
            if(cnt>=4){
                flag=false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < m; j2++) {
                        if(cs[i][j]=='B'&&cs[i2][j2]=='B'&&cs[i][j2]=='W'&&cs[i2][j]=='W'){
                            flag=false;
                            break;
                        }
                    }
                }
            }
        }
        System.out.println(flag?"YES":"NO");
    }
}
