import java.io.*;

public class c1217 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args)throws Exception{
        int t = Integer.parseInt(br.readLine());
        while (t-->0){
            String s = br.readLine();
            int ans = 0,pre=0;//前导零
            for(int i=0;i<s.length();i++){
                if(s.charAt(i) == '0') pre++;
                else{
                    int r = i,cur=1;
                    for(int j=1;j<=18;j++){//题目条件推出最多18位
                        if(cur<=pre+(r-i+1)) ans++;
                        if(r+1 >= s.length()) break;
                        cur = cur*2+(s.charAt(++r)-'0');
                    }
                    pre = 0;
                }
            }
            pw.println(ans);
            pw.flush();
        }
    }
}
