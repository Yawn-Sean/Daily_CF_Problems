package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() {
	solveD(os.Stdin, os.Stdout)
}

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var T, n, q, s int
	for fmt.Fscan(in, &T); T > 0; T-- {
		fmt.Fscan(in, &n, &q)
		a, psum := make([]int, n), make([]int, n+1)
		for i := range a {
			fmt.Fscan(in, &a[i])
		}
		sort.Ints(a)
		for i, v := range a {
			psum[i+1] = psum[i] + v
		}
		mp := map[int]struct{}{}
		var dfs func(int, int)
		dfs = func(l, r int) {
			mp[psum[r+1]-psum[l]] = struct{}{}
			if a[l] != a[r] {
				mid := (a[l] + a[r]) / 2
				x := sort.SearchInts(a, mid+1)
				dfs(l, x-1)
				dfs(x, r)
			}
		}
		dfs(0, n-1)
		for ; q > 0; q-- {
			fmt.Fscan(in, &s)
			if _, ok := mp[s]; ok {
				fmt.Fprintln(out, "Yes")
			} else {
				fmt.Fprintln(out, "No")
			}
		}
	}
}
