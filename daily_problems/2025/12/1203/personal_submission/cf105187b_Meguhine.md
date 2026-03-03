设当前某个队伍的最好分数为 $x$

考虑其他的每一场比赛，设比之前两队的分数分别是 $mn,mx\,(mn\le mx)$，则有

- **IF** $mn>x$， $\text{rank}\leftarrow \text{rank}+2$
- **ELIF** ($mn\ge x-2$ **AND** $mx=x$) **OR** $mx>x$， $\text{rank}\leftarrow \text{rank}+1$
- **ELSE** $\text{rank}$ 不变

我们不妨按照 $x$ 从小到大的顺序去遍历，设一开始 $x=-1$，则每一对都有 $2$ 的贡献

我们把每一对按照 $mx-mn$ 进行分类

- $mx-mn>2$，此时只要在 $x\in\{mn,mx\}$ 的时候更新这一对的贡献即可
- $mx-mn\le 2$，此时暴力把 $x\in[mn,\max(mn+3,mx)]$ 的时候都更新，但由于 $mx-mn\le 2$ 的限制，复杂度依然正确
