public static void solve(){
    long n = sc.ni();
    char[] cs = sc.ns().toCharArray();
    Map<Long, Integer> map = new HashMap<>();
    int s = cs.length;
    for (int i = 0; i < s; i++) {
        long sum = 0;
        for (int j = i; j <s; j++) {
            sum += cs[j] -'0';
            map.merge(sum, 1,Integer::sum);
        }
    }
    long ans = 0;
    if(n == 0){
        long cnt = map.getOrDefault(0L, 0);
        ans += cnt *(s*(s+1)/2 - cnt) *2 + cnt * cnt;
        out.println(ans);
        return;
    }
    for (long i = 1; i*i <=n ; i++) {
        if(n%i==0){
            long c = 1;
            if(i!=n/i){
                c++;
            }
            ans += c*map.getOrDefault(i,0)*map.getOrDefault(n/i,0);
        }
    }
    out.println(ans);
}
