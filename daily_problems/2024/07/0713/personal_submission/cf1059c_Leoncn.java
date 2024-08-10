
public class cf1059c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int thing = n;
        while (thing > 3) {
            thing /= 2;
        }
        int one = 1;
        int rem = n;
        StringBuilder sb = new StringBuilder();
        while (rem > 1) {
            sb.append((one + " ").repeat(Math.max(0, (rem + 1) / 2)));
            rem /= 2;
            one *= 2;
        }
        if (thing == 3) sb.append((one/2)*3);
        else sb.append(one);
        out.println(sb);
    }
}
