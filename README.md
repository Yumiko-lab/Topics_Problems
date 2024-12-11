TODO: 

1. VSCode C++ 配置 + 调试
2. Sublime Text 4 C++ 配置 + 调试
3. Windows 和 Linux 环境下 C++ 对拍
4. 银牌算法模板整理


C++ 语法：

1. 泛型编程 —— 模板
   1. [清华算协暑期培训 第一讲 C++梳理](https://www.bilibili.com/video/BV15d4y1U7HH/): 00:44:00
   2. [黑马程序员 - 模板](https://www.bilibili.com/video/BV1et411b73Z/?vd_source=5e53118bdffba34d123bb97d9a7caf9a&p=167) 
2. STL




---

[五街教授 - 彻底搞懂vscode中配置c/c++环境，实现编译和调试以及远程linux - Bilibili](https://www.bilibili.com/video/BV1Bc411S7ch/) 

[改BUG的TOM学长 - vscode安装配置c/c++教程 - Bilibili](https://www.bilibili.com/video/BV1BQ4y1j7fY/) 

[GKxxISCAS - 关于搭环境（C/C++编译器和VSCode的安装、配置） - Bilibili](https://www.bilibili.com/video/BV1id4y1n7Kw/) 

[_重装小兔19C - 完美配置vscode运行c/c++环境，2022最新教程 - Bilibili](https://www.bilibili.com/video/BV1ge4y1J72t/) 

[Resot - 【竞赛工具】——vscode xcpc竞赛向配置教程 - Zhihu](https://zhuanlan.zhihu.com/p/705969825) 

[OI Wiki - VSCode](https://oi-wiki.org/tools/editor/vscode/) 

[dianhsu - 如何打造一个舒适的算法竞赛编程环境 - Cnblogs](https://www.dianhsu.com/2023/12/30/algorithm-env/) 

[RioTian - Windows VS Code 配置 C/C++ 开发环境 - Cnblogs](https://www.cnblogs.com/RioTian/p/13812319.html) 

---

[Kiyuim - 如何拥有jiangly蒋老师同款编译器(sublime c++配置 竞赛向） - Bilibili](https://www.bilibili.com/video/BV1qV411c7VL/) 

[Resot - 【竞赛工具】——sublime text4 xcpc竞赛向配置教程 - Zhihu](https://zhuanlan.zhihu.com/p/702816564) 

[OI Wiki - Sublime Text](https://oi-wiki.org/tools/editor/sublime/) 

[whoammiiiiii - sublime配置c++环境 X 算法竞赛 - CSDN](https://blog.csdn.net/qq_43555854/article/details/111644632) 

[Fr1nGeLove - 算法竞赛数据生成及使用Sublime对拍 - CSDN](https://blog.csdn.net/Fr1nGeLove/article/details/140684507) 

---


# 算法专题练习


## 算法题分类


- 搜索：
   1. DFS
   2. BFS



- 数学：
   1. 数论
   2. 组合数学
   3. 概率论
   4. 博弈论
   5. 群论


- 数据结构：
  1. 字典树 (Tire)
     1. //
  2. 树状数组
     1. //
  3. 线段树
     1. //
     2. 线段树合并
  4. 并查集
     1. 普通并查集
     2. 边带权并查集
     3. 扩展域并查集 (种类并查集)
     4. 可撤销并查集
  5. 可持久化
     1. 字典树
     2. 线段树
     3. 并查集
  6. 平衡树
     1. Treap
     2. Splay
     3. 树套树
  7. 分块
     1. 基本思想
     2. 块状链表
  8. 莫队
     1. 基础莫队
     2. 带修改的莫队
     3. 回滚莫队
     4. 树上莫队
     5. 二次离线莫队
  9.  动态树 (LCT: Link-Cut-Tree)
  10. 分治：
     1. 点分治
     2. 点分树
     3. CDQ分治


- 动态规划
   1. 动态规划基础
      - 原理：最优子结构 + 无后效性 + 子问题重叠
   2. 背包 DP
      1. 01 背包
      2. 完全背包
      3. 多重背包
      4. 混合背包
      5. 分组背包
   3. 记忆化搜索
   4. 线性 DP
   5. 区间 DP
   6. 树形 DP
      1. 基础树形 DP
         1. 最大权独立集
         2. 最小权覆盖集
      2. 树上背包
      3. 换根 DP (二次扫描法)
      4. 基环树
      5. 虚树
      6. 长链剖分
   7. 状压 DP
   8. 数位 DP
   9.  轮廓线 DP、插头 DP
   10. DP 套 DP
   11. 计数 DP、概率 DP
   12. DP 优化
       1.  单调队列/单调栈优化
       2.  决策单调性优化
       3.  斜率优化
       4.  四边形不等式优化
       5.  矩阵快速幂加速递推


( 可以用 LeetCode 复习，搭配灵茶山艾府整理的力扣题单 )



- 图论


---


图论复习顺序——

1. 拓扑排序

2. 最短路：
   - 单源最短路：
      1. Dijkstra
      2. Bellman-Ford
      3. SPFA
      4. 负环
      5. 差分约束



3. 连通性：
   1. SCC
   2. BCC
   3. 2-SAT



4. 最小生成树 ( 倍增 LCA 前置 )
   1. Prim
   2. Kruskal



5. 二分图：
   1. 二分图的判定
   2. 二分图的最大匹配 - 匈牙利算法



6. 多源最短路：
   1. Floyd ( 前置：矩阵乘法、DP )
   2. Johnson 




-----



( 不着急学习的内容 )

杂类：基环树 ( DP 之后 )

二分图进阶内容：

1. 二分图最小点覆盖
2. 二分图最大独立集
3. 有向无环图的最小路径点覆盖

匹配：

  1. 二分图
     1. 二分图的带权匹配
  2. 一般图：
     1. 一般图的最大匹配
     2. 一般图的带权匹配

- 流：
	1. 最大流
	2. 最小割
	3. 费用流


欧拉路径与欧拉回路 (useless)

-----




# 算法学习

## Acwing：

算法学习：
1. [算法基础课](https://www.acwing.com/activity/content/11/) 
2. [考研408-数据结构（笔试）](https://www.acwing.com/activity/content/48/) 
3. [考研408-数据结构（上机）](https://www.acwing.com/activity/content/3343/) 
4. [PAT甲级辅导课](https://www.acwing.com/activity/content/27/) 
5. [蓝桥杯辅导课](https://www.acwing.com/activity/content/19/) 
6. [LeetCode究极班](https://www.acwing.com/activity/content/31/) 
7. [算法提高课](https://www.acwing.com/activity/content/16/) 
8. [CSP-S 辅导课](https://www.acwing.com/activity/content/3444/) 
9. [算法进阶课](https://www.acwing.com/activity/content/32/) 
10. [USACO Training辅导课](https://www.acwing.com/activity/content/36/) 
11. [CCF-CSP认证辅导课](https://www.acwing.com/activity/content/39/) 


刷题：
1. [USACO月赛打卡活动](https://www.acwing.com/activity/content/89/) 
2. [kuangbin专题打卡活动](https://www.acwing.com/activity/content/90/) 
3. [每日一题 - 2021 ~ 2024](chrome://bookmarks/?id=453) 


项目学习：
1. [Java语法基础课](https://www.acwing.com/activity/content/2230/) 
2. [Linux基础课](https://www.acwing.com/activity/content/57/) 
3. [Django框架课](https://www.acwing.com/activity/content/72/) 
4. [Web应用课](https://www.acwing.com/activity/content/1150/) 


Python：

- [Python基础课](https://studio.youtube.com/playlist/PLZjK0Hj8Fi-18M4TD7cbiCzjtxqTLIe_6/videos) 





- [罗勇军<<算法竞赛>>配套题单 - Athanasy](https://www.luogu.com.cn/training/441063#information) 
- [《算法竞赛进阶指南》打卡活动 - Acwing](https://www.acwing.com/activity/content/6/) 


## Bilibili

[清华算协暑期培训](https://www.bilibili.com/video/BV15d4y1U7HH/) 



# 待刷题单

---


**算法模板学习——**

[算法竞赛模板库 by 灵茶山艾府](https://github.com/EndlessCheng/codeforces-go) 

---

**每日一题——**

- [每日羊蹄](https://github.com/Yawn-Sean/Daily_CF_Problems/tree/main) 
- [灵茶の试炼](https://docs.qq.com/sheet/DWGFoRGVZRmxNaXFz?tab=BB08J2) 

---


**构造题训练——**

- [Codeforces 构造题训练 - [1700 - 1900]](https://codeforces.com/problemset?order=BY_SOLVED_DESC&tags=constructive+algorithms%2C1700-1900) 
- [构造题专项训练 - Luogu](https://www.luogu.com.cn/training/14) 


---

**CSP——**

CCF-CSP (0 ~ 23)：

- [CCF-CSP认证辅导课 - Acwing](https://www.acwing.com/activity/content/39/) 


CSP-S (2003 - 2022)：

- [CSP-S 辅导课 - Acwing](https://www.acwing.com/activity/content/3444/) 


---

**各路选手的题单——**

李哥的构造题题单：

- [constructive marathon(div. 1)](https://codeforces.com/contests/412155) 
- [constructive marathon(div. 2)](https://codeforces.com/contests/413091) 


李哥的人生必做题题单：

- [人生必做题，让你成为见解独特的黑马选手](https://www.luogu.com.cn/training/597983) 



某一个人の题单大全：

- [某一个人の题单大全](https://zhuanlan.zhihu.com/p/716449304) 




ExtractStars 的题单：

- [ExtractStars](https://vjudge.net/user/ExtractStars) 


SpeedStar 的题单：

- [SpeedStar - Acwing](https://www.acwing.com/user/myspace/blog/7340/) 

---


**百度之星题单——**

- [2005年-2024年百度之星题集](https://www.matiji.net/exam/baiduzhixing) 



---

**DP 题单——**

- [新手动态规划合集 - Luogu](https://www.luogu.com.cn/training/1060) 
- [背包问题（简单） - Luogu](https://www.luogu.com.cn/training/8917) 
- [背包问题 - Luogu](https://www.luogu.com.cn/training/5197) 
- [xzy的树形dp题单 - Luogu](https://www.luogu.com.cn/training/11363) 
- [【动态规划】普及~省选的dp题 - Luogu](https://www.luogu.com.cn/training/1435) 
- [【动态规划】提高组的DP问候 - Luogu](https://www.luogu.com.cn/training/12927) 
- [面向tg选手的DP练习题 - Luogu](https://www.luogu.com.cn/training/1323) 
- [codeforces 2000左右的dp题 - Luogu](https://www.luogu.com.cn/training/3963) 
- [codeforces 2100左右的dp题 - Luogu](https://www.luogu.com.cn/training/3961) 
- [动态规划进阶 - Luogu](https://www.luogu.com.cn/training/3045) 
