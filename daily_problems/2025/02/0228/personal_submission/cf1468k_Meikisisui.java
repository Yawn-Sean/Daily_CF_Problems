import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            boolean isOk = false;
            // 障碍物
            int x = 0, y = 0;
            for (int ez = 0; ez < s.length(); ez++) {
                if (s.charAt(ez) == 'R') x++;
                else if (s.charAt(ez) == 'L') x--;
                else if (s.charAt(ez) == 'U') y++;
                else if (s.charAt(ez) == 'D') y--;
                // 机器人
                int robotX = 0, robotY = 0;
                for (int vn = 0; vn < s.length(); vn++) {
                    int a = robotX, b = robotY;
                    if (s.charAt(vn) == 'R') robotX++;
                    else if (s.charAt(vn) == 'L') robotX--;
                    else if (s.charAt(vn) == 'U') robotY++;
                    else if (s.charAt(vn) == 'D') robotY--;
                    if (robotX == x && robotY == y) {
                        robotX = a;
                        robotY = b;
                    }
                }
                // 走回原点
                if (robotX == 0 && robotY == 0) {
                    pw.println(x + " " + y);
                    isOk = true;
                    break;
                }
            }
            if (!isOk)
                pw.println(0 + " " + 0);
        }
        pw.close();
        br.close();
    }

}
