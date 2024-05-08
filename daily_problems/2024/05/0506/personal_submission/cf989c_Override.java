import java.util.Scanner;

public class c989 {
    public static void main(String[] args){
        int a,b,c,d;
        int[][] A = new int[55][55];
        Scanner sc = new Scanner(System.in);
        d = sc.nextInt();c =sc.nextInt();b=sc.nextInt();a=sc.nextInt();
        a--;b--;c--;d--;
        for(int i=1;i<=25;i++){
            for(int j=1;j<=25;j++){
                A[i][j] = 1;//A
            }
        }
        for(int i=1;i<=25;i++){
            for(int j=26;j<=50;j++){
                A[i][j] = 2;//B
            }
        }
        for(int i=26;i<=50;i++){
            for(int j=1;j<=25;j++){
                A[i][j] = 3;//C
            }
        }
        for(int i=26;i<=50;i++){
            for(int j=26;j<=50;j++){
                A[i][j] = 4;//D
            }
        }
        int x =1,y=1;
        for(int i=1;i<=a;i++){
            A[x][y]=4;//A里存D
            y+=2;//需要两列两列的替换
            if(y==26){y=1;x+=2;}
            if(y==27){y=2;x+=2;}
        }
        x=1;y=26;
        for(int i=1;i<=b;i++)
        {
            A[x][y]=3;//B里存C
            y+=2;
            if(y==51){y=26;x+=2;}
            if(y==52){y=27;x+=2;}
        }
        x=26;y=1;
        for(int i=1;i<=c;i++)
        {
            A[x][y]=2;//C里存B
            y+=2;
            if(y==26){y=1;x+=2;}
            if(y==27){y=2;x+=2;}
        }
        x=26;y=26;
        for(int i=1;i<=d;i++)
        {
            A[x][y]=1;//D里存A
            y+=2;
            if(y==51){y=26;x+=2;}
            if(y==52){y=27;x+=2;}
        }
        System.out.println(50+" "+50);
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                char ans = (char) ('A' + A[i][j] - 1);
                System.out.print(ans);
            }
            System.out.println();
        }
    }
}
