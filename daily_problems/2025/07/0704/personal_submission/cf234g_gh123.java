//https://codeforces.com/problemset/submission/234/327324669
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class G234 {
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(new File("input.txt"));
        PrintWriter output=new PrintWriter(new File("output.txt"));
        int n=sc.nextInt();
        int ans=0;
        int x=n;
        while (x!=1) {
            ans++;
            x=(x+1)/2;
        }   
        sc.close();
        StringBuilder sb=new StringBuilder();
        sb.append(ans).append('\n');
        for (int i = 0; i < ans; i++) {
            int mk=1<<i;
            int temp=0;
            StringBuilder team=new StringBuilder();
            for (int j = 0; j < n; j++) {
                if((j&mk)==0){
                    temp++;
                    team.append(' ').append(j+1);
                }
            }
            sb.append(temp).append(team).append('\n');
        }
        output.println(sb);
        output.close();
    }
}
