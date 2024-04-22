package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func solve(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, k, ans, a0 int
	Fscan(in, &n, &k)
	ss := make([]string, n)
	cnt := make([][]int, n+1)
	for i := range ss {
		Fscan(in, &ss[i])
	}
	for i := range cnt {
		cnt[i] = make([]int, n+1)
	}

	for i := 0; i < n; i++ {
		l, r := -1, -1
		for j, ch := range ss[i] {
			if ch == 'B' {
				if l == -1 {
					l = j
				}
				r = j
			}
		}
		if l != -1 && r-l+1 <= k {
			mni, mnj := max(0, i-k+1), max(0, r-k+1)
			cnt[mni][mnj]++
			cnt[mni][l+1]--
			cnt[i+1][mnj]--
			cnt[i+1][l+1]++
		}
		if l == -1 {
			a0++
		}
	}

	for i := 0; i < n; i++ {
		l, r := -1, -1
		for j := 0; j < n; j++ {
			if ss[j][i] == 'B' {
				if l == -1 {
					l = j
				}
				r = j
			}
		}
		if l != -1 && r-l+1 <= k {
			mni, mnj := max(0, r-k+1), max(0, i-k+1)
			cnt[mni][mnj]++
			cnt[mni][i+1]--
			cnt[l+1][mnj]--
			cnt[l+1][i+1]++
		}
		if l == -1 {
			a0++
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i > 0 {
				cnt[i][j] += cnt[i-1][j]
			}
			if j > 0 {
				cnt[i][j] += cnt[i][j-1]
			}
			if i > 0 && j > 0 {
				cnt[i][j] -= cnt[i-1][j-1]
			}
			ans = max(ans, cnt[i][j])
		}
	}

	Fprint(out, ans+a0)
}

func main() { solve(os.Stdin, os.Stdout) }
