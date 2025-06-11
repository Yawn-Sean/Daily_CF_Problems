import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        double nu, nd, nl, nr, mu, md, ml, mr, mx, my, x, y;
        nu = nr = mu = mr = -101;
        nd = nl = md = ml = 101;
        for (int i = 0; i < 4; i++) {
            x = Double.parseDouble(st.nextToken());
            y = Double.parseDouble(st.nextToken());
            nd = Math.min(nd, y);
            nu = Math.max(nu, y);
            nl = Math.min(nl, x);
            nr = Math.max(nr, x);
        }
        st = new StringTokenizer(f.readLine());
        for (int i = 0; i < 4; i++) {
            x = Double.parseDouble(st.nextToken());
            y = Double.parseDouble(st.nextToken());
            md = Math.min(md, y);
            mu = Math.max(mu, y);
            ml = Math.min(ml, x);
            mr = Math.max(mr, x);
        }
        mx = (ml + mr) / 2;
        my = (mu + md) / 2;
        if ((mx >= nl && mx <= nr && md >= nd && md <= nu) ||
                (mx >= nl && mx <= nr && mu >= nd && mu <= nu) ||
                (ml >= nl && ml <= nr && my >= nd && my <= nu) ||
                (mr >= nl && mr <= nr && my >= nd && my <= nu))
            pw.println("YES");
        else if ((nu + nr >= ml + my && nu <= nr - mx + mu && nu >= nr - mx + md && nu + nr <= mr + my) ||
                (nd + nr >= ml + my && nd <= nr - mx + mu && nd >= nr - mx + md && nd + nr <= mr + my) ||
                (nu + nl >= ml + my && nu <= nl - mx + mu && nu >= nl - mx + md && nu + nl <= mr + my) ||
                (nd + nl >= ml + my && nd <= nl - mx + mu && nd >= nl - mx + md && nd + nl <= mr + my))
            pw.println("YES");
        else if (mx >= nl && mx <= nr && my >= nd && my <= nu)
            pw.println("YES");
        else
            pw.println("NO");
        pw.close();
        f.close();
    }

}
