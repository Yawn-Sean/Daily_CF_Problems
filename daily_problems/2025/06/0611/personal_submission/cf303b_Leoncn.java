
public class cf303b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int x = sc.ni();
        int y = sc.ni();
        int a = sc.ni();
        int b = sc.ni();
        int g = gcd(a, b);

        a = a/g;
        b = b/g;
        int min = Math.min(n/a, m/b);
        int k = min * a;
        int h = min * b;
        int ans1 = Math.min(n-k, Math.max(x- (k+1)/2, 0));
        int ans2 = Math.min(m-h, Math.max(y- (h+1)/2, 0));
        out.println(ans1 + " " + ans2 + " " + (ans1+k) + " " + (ans2+h) );
    }
}
