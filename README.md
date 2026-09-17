# ACM 竞赛知识点仓库

> 记录 ACM-ICPC / CCPC 竞赛学习笔记与竞赛代码模板，按算法大类组织，每个具体算法独立成文。

## 目录结构

```
.
├── notes/              # 知识点笔记
│   ├── basic/           # 基础算法（排序、二分、贪心...）
│   ├── data-structure/  # 数据结构（线段树、并查集、树状数组...）
│   ├── graph/           # 图论（最短路、最小生成树、网络流...）
│   ├── dp/              # 动态规划（背包、区间DP、树形DP、计数DP...）
│   ├── string/          # 字符串（KMP、Trie、AC自动机、SAM...）
│   ├── math/            # 数学（数论、组合数学、矩阵快速幂...）
│   ├── geometry/        # 计算几何（凸包、旋转卡壳、半平面交...）
│   └── misc/            # 杂项（位运算、博弈论、随机化...）
├── templates/          # 竞赛代码模板（可直接复制使用）
│   ├── basic/
│   ├── data-structure/
│   ├── graph/
│   ├── dp/
│   ├── string/
│   ├── math/
│   ├── geometry/
│   └── misc/
└── docs/
    └── study-guide.md   # 学习路线与刷题指南
```

**notes 与 templates 的 8 个分类一一对应**。笔记中通过相对路径链接到对应模板。

## 分类索引

### 基础算法

| 笔记 | 模板 | 简介 |
|------|------|------|
| [排序](notes/basic/sort.md) | — | STL 排序、归并求逆序对 |
| [二分查找](notes/basic/binary-search.md) | [binary_search.cpp](templates/basic/binary_search.cpp) | lower/upper_bound、答案二分 |

### 数据结构

| 笔记 | 模板 | 简介 |
|------|------|------|
| [线段树](notes/data-structure/segment-tree.md) | [segment_tree.cpp](templates/data-structure/segment_tree.cpp) | 区间加 + 区间求和 |

### 图论

| 笔记 | 模板 | 简介 |
|------|------|------|
| [最短路径](notes/graph/shortest-path.md) | [dijkstra.cpp](templates/graph/dijkstra.cpp) | Dijkstra、SPFA、Floyd |

### 动态规划

| 笔记 | 模板 | 简介 |
|------|------|------|
| [背包 DP](notes/dp/knapsack.md) | [knapsack_01.cpp](templates/dp/knapsack_01.cpp) | 01 背包、完全背包 |

### 数学

| 笔记 | 模板 | 简介 |
|------|------|------|
| — | [fast_power.cpp](templates/math/fast_power.cpp) | 快速幂、龟速乘 |

## 笔记格式规范

每篇笔记固定结构：

1. **简介** — 一句话概括
2. **核心思想** — 算法本质
3. **算法流程** — 关键步骤
4. **复杂度** — 时间 / 空间
5. **模板** — 链接到对应 `.cpp`
6. **典型例题** — 题目链接

## 模板格式规范

- 文件头注释包含：算法名、时间/空间复杂度、功能说明、关键步骤、编译命令
- 代码体内**仅关键步骤保留少量注释**，其余说明全部写在文件头
- 每个文件完整可编译，含 `main` 函数

## VSCode 使用

1. 用 VSCode 打开仓库根目录
2. 安装推荐扩展（弹出提示时点击安装）：C/C++、Code Runner、Competitive Programming Helper
3. 编辑后通过左侧 **源代码管理** 面板提交，点击同步更改推送到 GitHub

## License

个人学习笔记，仅供学习交流。
