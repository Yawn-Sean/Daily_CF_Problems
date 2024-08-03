package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1148D(os.Stdin, os.Stdout) }

// CF1148D https://codeforces.com/contest/1148/submission/254660763
func CF1148D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, a, b int
	for t = 1; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		var lt, gt []int
		points := make([][]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a, &b)
			points[i] = append(points[i], a)
			points[i] = append(points[i], b)
			if a < b {
				lt = append(lt, i)
			} else {
				gt = append(gt, i)
			}
		}
		if len(lt) >= len(gt) {
			sort.Slice(lt, func(i, j int) bool {
				return points[lt[i]][1] > points[lt[j]][1]
			})
			fmt.Fprintf(out, "%d\n", len(lt))
			for i := 0; i < len(lt); i++ {
				fmt.Fprintf(out, "%d ", lt[i]+1)
			}
		} else {
			sort.Slice(gt, func(i, j int) bool {
				return points[gt[i]][1] < points[gt[j]][1]
			})
			fmt.Fprintf(out, "%d\n", len(gt))
			for i := 0; i < len(gt); i++ {
				fmt.Fprintf(out, "%d ", gt[i]+1)
			}
		}
	}
}
