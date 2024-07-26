package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1023D(os.Stdin, os.Stdout) }

// https://codeforces.com/problemset/submission/1023/272474976
func CF1023D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, q int
	fmt.Fscan(in, &n, &q)
	a := make([]int, n)
	mx := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		mx = max(mx, a[i])
	}
	tr := BuildSegmentTreeRangeMin(a)
	i := 0
	mp := map[int]int{}
	used := false
	if mx == q { // 最大值是否已经用过
		used = true
	}
	for i < n {
		if a[i] == 0 {
			if !used {
				a[i] = q
				used = true
				continue
			}
			if i > 0 {
				a[i] = a[i-1]
				mp[a[i]] = i
				tr.Update(i, a[i])
				i++
				continue
			}
			start := i
			for i < n && a[i] == 0 {
				i++
			}
			for j := start; j < i; j++ {
				a[j] = a[i]
				tr.Update(j, a[j])
			}
			continue
		}
		idx, exist := mp[a[i]]
		if exist {
			v := tr.QueryRange(idx, i-1)
			if v < a[i] {
				fmt.Fprintf(out, "NO")
				return
			}
		}
		mp[a[i]] = i
		tr.Update(i, a[i])
		i++
	}
	if !used {
		fmt.Fprintf(out, "NO")
		return
	}
	fmt.Fprintf(out, "YES\n")
	for i = 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", a[i])
	}
}

