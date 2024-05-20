//从头开始遍历  判断状态
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class a917 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int tot=0,ans=0,num=0;
    public static void main(String[] args)throws Exception{
        String s= br.readLine();
        int len = s.length();

        for(int i=0;i<len;i++){
            tot = 0;num=0;//tot 表示当前括号状态  num 可以修改的右括号
            for(int j=i;j<len;j++){
                if(s.charAt(j) == '(') tot++;
                if(s.charAt(j) == ')') tot--;
                if(s.charAt(j) == '?') {
                    if(tot>0){
                        tot--;num++;
                    }else{
                        tot++;
                    }
                }

                if(tot<0 && num>0){
                    tot+=2;num--;
                }
                if(tot<0 && num==0){
                    break;
                }
                if(tot == 0) ans++;
            }

        }
        System.out.println(ans);
    }

}
