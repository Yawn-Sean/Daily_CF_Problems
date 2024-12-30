package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

type pair struct{ x, y int }

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m int
	Fscan(in, &n, &m)
	votes := make([]pair, n)
	for i := range votes {
		Fscan(in, &votes[i].y, &votes[i].x)
	}
	sort.Slice(votes, func(i, j int) bool { return votes[i].x < votes[j].x })

	ans := int(1e18)
	for i := 1; i <= n; i++ {
		change := make([]bool, n)
		cnt := make([]int, m)
		sum := 0
		for j := n - 1; j >= 0; j-- {
			if votes[j].x == 1 {
				cnt[0]++
			} else {
				cnt[votes[j].x-1]++
				if cnt[votes[j].x-1] >= i {
					change[j] = true
					sum += votes[j].y
					cnt[votes[j].x-1]--
					cnt[0]++
				}
			}
		}
		for j, p := range votes {
			if cnt[0] >= i {
				break
			}
			if !change[j] && p.x != 1 {
				sum += p.y
				cnt[0]++
				cnt[p.x-1]--
			}
		}
		ans = min(ans, sum)
	}
	Fprintln(out, ans)
}

func main() {
	solve(os.Stdin, os.Stdout)
}
