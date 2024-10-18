
public class cf74c_Leoncn {
    public static void solve() {
        int a = sc.ni();
        int b = sc.ni();
        out.println(BigInteger.valueOf(a-1).gcd(BigInteger.valueOf(b-1)).intValue()+1);
    }
}
