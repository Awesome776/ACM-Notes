# 最短路径

## 概述

最短路径问题是图论中的核心问题：给定带权图，求从一个源点到其他所有顶点的最短路径。

## 主要算法对比

| 算法 | 时间复杂度 | 适用图 | 特点 |
|------|-----------|--------|------|
| Dijkstra | O((V+E) log V) | 非负权 | 优先队列优化，最常用 |
| Bellman-Ford | O(VE) | 可含负权 | 可判负环 |
| SPFA | ~O(kE)，最坏 O(VE) | 可含负权 | Bellman-Ford 的队列优化 |
| Floyd | O(V³) | 任意图 | 求所有点对最短路 |

## Dijkstra 算法

### 核心思想

贪心策略：每次从未确定最短路的节点中选出距离最小的，确定其最短路，然后用它更新邻接节点。

### 关键点

1. 适用于**非负权图**，若含负权边则不适用
2. 使用**优先队列（小根堆）**优化，复杂度 O((V+E) log V)
3. 注意**重边**和**自环**的处理

### 算法流程

```
1. dist[s] = 0, 其余 dist[i] = INF
2. 将 (0, s) 入堆
3. 循环直到堆空:
   a. 取出堆顶 (d, u)，若 d > dist[u] 则跳过（过期节点）
   b. 遍历 u 的邻接边 (u, v, w):
      若 dist[u] + w < dist[v]:
        dist[v] = dist[u] + w
        将 (dist[v], v) 入堆
```

## Bellman-Ford / SPFA

- **Bellman-Ford**：对所有边松弛 V-1 轮，若第 V 轮仍能松弛则存在负环
- **SPFA**：用队列优化，期望复杂度 O(kE)，但可被构造数据卡到 O(VE)

## Floyd 算法

三重循环求所有点对最短路，适合 V 较小（≤ 500）的稠密图：

```cpp
for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
```

## 模板

详见 [dijkstra.cpp](../../templates/graph/dijkstra.cpp)，使用优先队列优化的 Dijkstra。

## 典型例题

- [洛谷 P4779 单源最短路](https://www.luogu.com.cn/problem/P4779) — Dijkstra 标准模板题
- [洛谷 P3385 负环](https://www.luogu.com.cn/problem/P3385) — SPFA 判负环
