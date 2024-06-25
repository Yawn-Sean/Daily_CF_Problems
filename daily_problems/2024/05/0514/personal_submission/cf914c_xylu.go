package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
	"os"
)

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n string
	var k int
	fmt.Fscan(in, &n, &k)
	if k == 0 {
		fmt.Fprintln(out, 1)
		return
	}

	q := []int{1}
	for i := 0; i < k-1; i++ {
		tmp := []int{}
		for _, x := range q {
			for j := 2; j < 1000; j++ {
				if bits.OnesCount(uint(j)) == x {
					tmp = append(tmp, j)
				}
			}
		}
		q = tmp
	}

	mod := int(1e9 + 7)
	memo := make([][]int, len(n))
	for i := range memo {
		memo[i] = make([]int, 1000)
		for j := range memo[i] {
			memo[i][j] = -1
		}
	}

	var dfs func(int, int, bool, bool) int
	dfs = func(pos, need int, limit, isnum bool) int {
		if pos == len(n) {
			if need == 0 {
				return 1
			}
			return 0
		}
		if !limit && isnum && memo[pos][need] != -1 {
			return memo[pos][need]
		}
		res := 0
		for i := 0; i <= min(need, 1); i++ {
			if limit && i > int(n[pos]-'0') {
				break
			}
			res += dfs(pos+1, need-i, limit && i == int(n[pos]-'0'), isnum || i > 0)
			res %= mod
		}
		if !limit && isnum {
			memo[pos][need] = res
		}
		return res
	}

	ans := 0
	for _, x := range q {
		ans += dfs(0, x, true, false)
		ans %= mod
	}
	// 去掉1
	if k == 1 {
		ans = (ans + mod - 1) % mod
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solve(os.Stdin, os.Stdout)
}
