//https://codeforces.com/problemset/submission/321/325086898
import java.util.Scanner;

public class A321 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt(),y=sc.nextInt();
        char[]cs=sc.next().toCharArray();
        int a=0,b=0;
        for (int i = 0; i < cs.length; i++) {
            if(cs[i]=='U') b++;
            if(cs[i]=='D') b--;
            if(cs[i]=='L') a--;
            if(cs[i]=='R') a++;
        }
        for (int i = -1; i < cs.length; i++) {
            char ch;
            if(i==-1){
                ch=0;
            }else ch=cs[i];
            if(ch=='U'){
                y--;
            }
            if(ch=='D'){
                y++;
            }
            if(ch=='L'){
                x++;
            }
            if(ch=='R'){
                x--;
            }
            if(a==0||b==0){
                if(a==0&&b==0){
                    if(x==0&&y==0){
                        System.out.println("Yes");
                        break;
                    }
                }else if(b==0&&y==0){
                    if(x%a==0&&x/a>=0){
                        System.out.println("Yes");
                        break;
                    }
                }else if(a==0&&x==0){
                    if(y%b==0&&y/b>=0){
                        System.out.println("Yes");
                        break;
                    }
                }
            }else if(y%b==0&&x%a==0&&y/b==x/a&&y/b>=0){
                System.out.println("Yes");
                break;
            }
            if(i==cs.length-1){
                System.out.println("No");
            }
        }
    }
}
