public class cfsubmit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int a = sc.nextInt();
        List<String> list = new ArrayList<>();
        Map<String,Long> map_s = new HashMap<>();
        Map<String,Long> map_h = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i <= a; i++) {
            String str = sc.nextLine();
            if(str.isEmpty()) continue;
            list.add(str);
            long s = count(str,'s');
            long h = count(str,'h');
            map_s.put(str,s);
            map_h.put(str,h);
        }
        list.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(map_h.get(o1) * map_s.get(o2) - map_s.get(o1) * map_h.get(o2) > 0) return 1;
                else if(map_h.get(o1) * map_s.get(o2) - map_s.get(o1) * map_h.get(o2) < 0) return -1;
                else return 0;
            }
        });
        for (String string : list) {
            sb.append(string);
        }
        int counts = 0;
        long ans = 0;
        for (int i = 0; i < sb.length(); i++) {
            if(sb.charAt(i) == 'h')  ans += counts;
            else counts++;
        }
        out.println(ans);
        sc.close();
        out.close();
    }
    public static long count(String str,char i){
        long count = 0;
        for (int j = 0; j < str.length(); j++) {
            if(str.charAt(j) == i) count++;
        }
        return count;
    }
}
