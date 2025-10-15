import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a1 = Integer.parseInt(st.nextToken());
        int a2 = Integer.parseInt(st.nextToken());
        int a3 = Integer.parseInt(st.nextToken());
        int a4 = Integer.parseInt(st.nextToken());
        if (Math.abs(a3 - a4) > 1) {
            pw.println("-1");
            pw.close();
            return;
        }
        if (a3 == a4) {
            if (a1 < 2 && a2 < 2) {
                pw.println("-1");
                pw.close();
                return;
            }
            if (a1 - 1 >= a3 && a2 >= a3) {
                a1 = a1 - a3 - 1;
                a2 = a2 - a3;
                for (int ez = 0; ez < a1; ez++) pw.print("4");
                for (int ez = 0; ez < a3; ez++) pw.print("47");
                for (int ez = 0; ez < a2; ez++) pw.print("7");
                pw.print("4");
            } else if (a2 - 1 >= a3 && a1 >= a3) {
                a2 = a2 - 1 - a3;
                pw.print("7");
                for (int ez = 0; ez < a3; ez++) pw.print("47");
                for (int ez = 0; ez < a2; ez++) pw.print("7");
            } else {
                pw.println("-1");
                pw.close();
                return;
            }
        } else if (a3 > a4) {
            a1 = a1 - a3;
            a2 = a2 - a3;
            if (a1 < 0 || a2 < 0) {
                pw.println("-1");
                pw.close();
                return;
            }
            for (int ez = 0; ez < a1; ez++) pw.print("4");
            for (int ez = 0; ez < a3; ez++) pw.print("47");
            for (int ez = 0; ez < a2; ez++) pw.print("7");
        } else {
            a1 = a1 - a4;
            a2 = a2 - a4;
            if (a1 < 0 || a2 < 0) {
                pw.println("-1");
                pw.close();
                return;
            }
            pw.print("7");
            for (int ez = 0; ez < a1; ez++) pw.print("4");
            for (int ez = 0; ez < a3; ez++) pw.print("47");
            for (int ez = 0; ez < a2; ez++) pw.print("7");
            pw.print("4");
        }
        pw.close();
    }


}
