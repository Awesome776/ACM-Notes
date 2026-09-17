# 最短路径

## 简介

给定带权图，求源点到其他所有顶点的最短路径。

## 核心思想

**Dijkstra**（非负权）：贪心——每次取距离最小的未确定节点，确定其最短路，松弛邻接边。

## 算法流程

1. `dist[s] = 0`，其余 `dist[i] = INF`，源点入优先队列
2. 循环：取出堆顶 `(d, u)`，若 `d > dist[u]` 跳过（过期节点）
3. 遍历 `u` 的邻接边 `(u, v, w)`：若 `dist[u] + w < dist[v]`，更新 `dist[v]` 并入堆
4. 队列为空时 `dist[]` 即为答案

## 复杂度

| 算法 | 时间 | 适用 |
|------|------|------|
| Dijkstra（堆优化） | O((V+E) log V) | 非负权 |
| SPFA | ~O(kE)，最坏 O(VE) | 可含负权 |
| Floyd | O(V³) | 全源最短路 |

## 模板

→ [dijkstra.cpp](../../templates/graph/dijkstra.cpp)（堆优化 Dijkstra）

## 典型例题

- [洛谷 P4779 单源最短路](https://www.luogu.com.cn/problem/P4779) — Dijkstra 模板
- [洛谷 P3385 负环](https://www.luogu.com.cn/problem/P3385) — SPFA 判负环
