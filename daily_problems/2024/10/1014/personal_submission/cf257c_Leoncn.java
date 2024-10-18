public static void solve() {
    int n = sc.ni();
    List<Double> list = new ArrayList<>();
    for (int i = 0; i < n; i++) {
        int a = sc.ni();
        int b = sc.ni();
        if(a == b && a == 0){
            continue;
        }
        double c = Math.atan2(b,a)* 180 / Math.PI;
        list.add(c);
    }
    list.sort(Double::compare);
    double ans = 0;

    for (int i = 0; i < list.size(); i++) {
        double b = list.get((i+1)%n);
        double a = list.get(i);
        ans = Math.max(ans, (b-a + 360)%360);
    }
    out.println(360-ans== 360?0: 360-ans);
}