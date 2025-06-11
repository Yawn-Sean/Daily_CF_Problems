package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func solveE(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	ss := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &ss[i])
	}
	pnum := ""
	for i, s := range ss {
		if !strings.Contains(s, "?") {
			a, _ := strconv.Atoi(s)
			b, _ := strconv.Atoi(pnum)
			if a <= b {
				fmt.Fprintln(out, "NO")
				return
			} else {
				pnum = s
				continue
			}
		}
		if len(s) < len(pnum) {
			fmt.Fprintln(out, "NO")
			return
		} else if len(s) > len(pnum) {
			bs := []byte(s)
			for i, ch := range bs {
				if ch == '?' {
					if i == 0 {
						bs[i] = '1'
					} else {
						bs[i] = '0'
					}
				}
			}
			pnum = string(bs)
		} else {
			preq, comp := []int{}, 0
			bs := []byte(s)
			for i, ch := range bs {
				if ch != '?' {
					if comp == 1 {
						continue
					}
					if bs[i] < pnum[i] {
						if len(preq) == 0 {
							fmt.Fprintln(out, "NO")
							return
						}
						for i := len(preq) - 1; i >= 0; i-- {
							if bs[preq[i]] < '9' {
								bs[preq[i]]++
								comp = 1
								// reset the rest of the digits to 0
								for j := i + 1; j < len(preq); j++ {
									bs[preq[j]] = '0'
								}
								break
							}
							if i == 0 {
								fmt.Fprintln(out, "NO")
								return
							}
						}
					} else if bs[i] > pnum[i] {
						comp = 1
					}
				} else {
					preq = append(preq, i)
					if comp == 1 {
						bs[i] = '0'
					} else {
						bs[i] = pnum[i]
					}
				}
			}
			if comp == 0 {
				for i := len(preq) - 1; i >= 0; i-- {
					if bs[preq[i]] < '9' {
						bs[preq[i]]++
						comp = 1
						for j := i + 1; j < len(preq); j++ {
							bs[preq[j]] = '0'
						}
						break
					}
					if i == 0 {
						fmt.Fprintln(out, "NO")
						return
					}
				}
			}
			pnum = string(bs)
		}
		ss[i] = pnum
	}
	fmt.Fprintln(out, "YES")
	for _, s := range ss {
		fmt.Fprintln(out, s)
	}
}

func main() {
	solveE(os.Stdin, os.Stdout)
}
