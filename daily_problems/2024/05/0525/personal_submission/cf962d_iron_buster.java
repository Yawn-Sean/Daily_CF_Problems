package com.fqh.heap;

import java.io.*;
import java.util.*;

/**
 * @author ikun
 * @version v1.0.0
 * @since 2024/5/25 15:18
 **/
public class CF_962D {

    // https://codeforces.com/problemset/problem/962/D

    public static void solve() throws IOException {
        int n = in.nextInt();
        var a = new long[n];
        var pq = new PriorityQueue<Integer>((i, j) -> a[i] != a[j] ? Long.compare(a[i], a[j]) : i - j);
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            pq.offer(i);
        }
        var ans = new ArrayList<Integer>();
        while (pq.size() > 1) {
            int p1 = pq.poll();
            int p2 = pq.poll();
            if (a[p1] == a[p2]) { // merge
                a[p2] *= 2;
                pq.offer(p2);
            } else {
                ans.add(p1);
                pq.offer(p2);
            }
        }
        if (!pq.isEmpty()) {
            ans.add(pq.peek());
        }
        Collections.sort(ans);
        out.println(ans.size());
        for (int i : ans) {
            out.print(a[i] + " ");
        }
        out.println();
    }
}
