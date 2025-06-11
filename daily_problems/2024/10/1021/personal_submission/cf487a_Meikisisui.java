import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int hpy = Integer.parseInt(st.nextToken());
        int atky = Integer.parseInt(st.nextToken());
        int defy = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int hpm = Integer.parseInt(st.nextToken());
        int atkm = Integer.parseInt(st.nextToken());
        int defm = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int hs = Integer.parseInt(st.nextToken());
        int as = Integer.parseInt(st.nextToken());
        int ds = Integer.parseInt(st.nextToken());
        int MinPrice = Integer.MAX_VALUE;
        int hp = 0, time = 0;
        for (int att = 0; att <= 200; att++) {
            for (int def = 0; def <= 100; def++) {
                int hitY = Math.max(0, atkm - defy - def);
                int hitM = Math.max(0, atky - defm + att);
                if (hitM == 0)
                    continue;
                time = (int) Math.ceil(hpm * 1.0 / hitM);
                if (time == 0)
                    time = 1;
                hp = Math.max(0, time * hitY - hpy + 1);
                MinPrice = Math.min(MinPrice, att * as + def * ds + hp * hs);
            }
        }
        pw.print(MinPrice);
        pw.close();
        f.close();
    }

}
