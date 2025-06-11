//https://codeforces.com/problemset/submission/405/286634547
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//直接用scanner就超时。。。

public class C405 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int sum=0;
        for (int i = 0; i < n; i++) {
            sum+=Integer.parseInt((br.readLine()).split(" ")[i]);
        }
        sum%=2;
        StringBuilder sb=new StringBuilder();
        int q=Integer.parseInt(br.readLine());
        while (q-->0) {
            int a=Integer.parseInt(br.readLine().split(" ")[0]);
            if(a==1||a==2){
                if(sum==0){
                    sum=1;
                }else{
                    sum=0;
                }
            }else{
                sb.append(sum);
            }
        }
        System.out.println(sb.toString());
    }

}
