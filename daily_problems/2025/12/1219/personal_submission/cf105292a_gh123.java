import java.util.Scanner;

public class A105292 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt();
        char[][]cs=new char[n][m];
        for (int i = 0; i < n; i++) {
            cs[i]=sc.next().toCharArray();
        }   
        sc.close();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(cs[i][j]=='.'){
                    cs[i][j]='L';
                    for (int x = i+1; x < n; x++) {
                        if(cs[x][j]=='#')break;
                        cs[x][j]='*';
                    }
                    for (int y = j+1; y < m; y++) {
                        if(cs[i][y]=='#')break;
                        cs[i][y]='*';
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(cs[i][j]=='*'){
                    cs[i][j]='.';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(String.valueOf(cs[i]));
        }
    }
}
