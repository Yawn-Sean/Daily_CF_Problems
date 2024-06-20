
public class cf678d_Leoncn {
    public static void solve() {
        int a = sc.ni();
        int b = sc.ni();
        long n = sc.nl();
        long x = sc.ni();
        int mod = (int)1e9+7;
        if(a == 1){
            out.println((x + n%mod*b%mod)%mod);
            return;
        }
        BigInteger f = BigInteger.valueOf(a).modPow(BigInteger.valueOf(n),BigInteger.valueOf(mod));
        BigInteger h = (BigInteger.valueOf(b).multiply(BigInteger.valueOf(a-1).modPow(BigInteger.valueOf(mod-2),BigInteger.valueOf(mod))));
        BigInteger d = BigInteger.valueOf(x).add(h);
        f = f.multiply(d).subtract(h).mod(BigInteger.valueOf(mod));
        out.println(f.intValue());
    }
}
