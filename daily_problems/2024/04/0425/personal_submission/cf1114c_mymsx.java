public class cfsubmit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        
        long a = sc.nextLong();
        long b = sc.nextLong();
        List<long[]> list = new ArrayList<>();
        for (int i = 2; i < b + 1; i++) {
            if((long) i * i > b) break;
            if(b % i == 0){
                long cnt = 0;
                while (b % i == 0){
                    cnt += 1;
                    b /= i;
                }
                list.add(new long[]{i,cnt});
            }
        }
        long ans = Long.MAX_VALUE;
        if(b > 1) list.add(new long[]{b,1});
        for (long[] ints : list) {
            long temp = a;
            long cnt = 0;
            while (temp > 0) {
                temp /= ints[0];
                cnt += temp;
            }
            ans = Math.min(ans, cnt / ints[1]);
        }
        out.print(ans);
        sc.close();
        out.close();
    }
}
