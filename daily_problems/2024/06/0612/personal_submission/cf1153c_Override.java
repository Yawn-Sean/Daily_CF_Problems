
import java.util.Scanner;

public class c1153 {
    public static void main(String[] args)throws Exception{
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        //读取换行
        String huang = scanner.nextLine();  //next不够  有时候比如牛客 lanqiao对这个没有影响 cf和本地需要注意
        //或者单纯使用br的readline
        char[] str = scanner.nextLine().toCharArray();
//        System.out.println(str[0]);

        int cnt = 0;
        for(char a : str){
            cnt += (a=='(')? 1:0;
        }
        int left = n/2-cnt;
        int cur = 0;

        for(int i=0;i<n;i++){
            if(str[i] == '('){
                cur++;
            }else if(str[i] == ')'){
                cur--;
            }else if(left>0){
                str[i] = '(';cur++;left--;
            }else{
                str[i] = ')';cur--;
            }
            if(cur<=0 && i!=n-1){
                System.out.println(":(");
                return;
            }
        }

        //Input
        //1
        //?  小心特例
        if(cur==0) System.out.println(str);
        else System.out.println(":(");

    }
}
