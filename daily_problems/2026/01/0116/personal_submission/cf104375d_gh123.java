import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
 
        List<Integer> nums = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nums.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(nums);
 
        StringBuilder sb = new StringBuilder();
        while (q-- > 0) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
 
            if (t == 1) {
                int v = Integer.parseInt(st.nextToken());
                if (nums.isEmpty() || v > nums.get(nums.size() - 1)) {
                    nums.add(v);
                } else {
                    int pos = findUpperBound(nums, v);
                    if (pos > 0 && nums.get(pos - 1) == v) {
                        continue;
                    } else {
                        nums.set(pos, v);
                    }
                }
            } else {
                int l = Integer.parseInt(st.nextToken());
                int r = Integer.parseInt(st.nextToken());
 
                int count = findUpperBound(nums, r) - findLowerBound(nums, l);
                sb.append(count).append('\n');
            }
        }
        System.out.print(sb.toString());
    }
 
    private static int findLowerBound(List<Integer> list, int v) {
        int left = 0;
        int right = list.size() - 1;
        int ans = list.size(); 
 
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) >= v) {
                ans = mid;    
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
 
    private static int findUpperBound(List<Integer> list, int v) {
        int left = 0;
        int right = list.size() - 1;
        int ans = list.size(); 
 
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) > v) {
                ans = mid;    
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
}
