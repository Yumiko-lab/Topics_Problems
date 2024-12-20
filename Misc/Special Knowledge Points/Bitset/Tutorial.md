# Bitwise Operations

[dls - 第十节：bitset - Misc](https://www.youtube.com/watch?v=xrWOrCMVNAQ) 

## Builtin Function


```cpp
__builtin_popcount(x) // x 二进制表达式中 1 的个数 (unsigned int)

__builtin_parity(x) // x 二进制表达式中 1 的个数的奇偶性 (unsigned int)

__builtin_ctz(x) // x 二进制表达式中末尾 0 的个数 (unsigned int)
__builtin_clz(x) // x 二进制表达式中前导 0 的个数 (unsigned int)
log2(x) = 31 - __builtin_clz(x) = __lg(x)
```

( 以上所有 C++ 内置 builtin 函数的时间复杂度都是 $\mathcal{O(1)}$ 的 )

> 形如 `__builtin_..` 在末尾加上 `ll` 都表示 `unsigned long long`


## Bitset

> 参考博客：
> 
> - [喵喵喵喵子 - C++ std::bitset 用法 - Blog - Acwing](https://www.acwing.com/blog/content/18626/) 
> - [OI Wiki - bitset](https://oi-wiki.org/lang/csl/bitset/) 
> - [anthony1314 - C++ bitset用法 - NowCoder](https://blog.nowcoder.net/n/45218f11e93842788069886a6d097484) 
> - [一扶苏一 - 扶苏的bitset浅谈 - Luogu](https://www.luogu.com.cn/article/osrhh40p) 






```cpp
bitset<1000> a = bool a[1000] // 长度为 1000 的 bool 数组
```

`bitset` 底层是用 `unsigned long long` 实现的，相当于用若干个 `unsignecd long long` 拼起来对应的位数。

好处：
    1. 压位，比直接开 bool 数组更省内存。
    2. 扩展 `unsigned int/long long` 状态压缩，单个数组不止 `32/64` 位，可自由设置。
    3. 支持 `&, |, ^` 等位运算**直接操作**。


时空复杂度都从 $\mathcal{O(n)} \implies \mathcal{O(\dfrac nw)}$，$w$ 表示字长，一般是 $64$，取决于计算机是 $32$ 位还是 $64$ 位机器。



常用成员函数：

1. `.count()`：$1$ 的个数
2. `.any()`：是否存在 $1$ 
3. `.none()`：是否全是 $0$ 
4. `.all()`：是否全是 $1$ 
5. `.to_string()`：返回转化成的字符串表达 (高位在前)
6. `.to_ulong()`：返回转换成的 `unsigned long` 
7. `.to_ullong()`：返回转换成的 `unsigned long long`


其它成员函数：

1. `.set(x)`：把第 $x$ 位变成 $1$ 
2. **`.set()`：把所有位变成 $1$**
3. `.reset(x)`：把第 $x$ 位变成 $0$ 
4. **`.reset()`：把所有位变成 $0$ ( 类似 `clear()` )**
5. `.flip(x)`；把第 $x$ 位反转 ( $0 \rightarrow 1, 1 \rightarrow 0$ )
6. **`.flip()`：把所有位反转**

( `set(x)` 和 `reset(x)` 以及 `flip(x)` 和下标遍历直接赋值几乎没有区别 )


特殊成员函数：

1. `._Find_first()`：从低位开始找第一个等于 $1$ 的位置
2. `.Find_next(i)`：从 $i$ 往高位找下一个 $1$ 的位置 ( 找不到范围 bitset 的最大范围 )

> 注意这两个函数 Mac 系统里没有，但 Codeforces 里有。

用法：

```cpp
for (int i = B._Find_first(); i != B.size(); i = B._Find_next(i)) {
    cout << i << ' ';
}
```
( 时间复杂度需要加上容器中 $1$ 的个数 )


以上成员函数时间复杂度都是 $\mathcal{O(\dfrac nw)}$。



比较流氓的写法 ( 不常用 )：

```cpp
bitset<N> a;

auto pa = (ull*)&a; // pa = bitset a 的地址

cout << pa[0] << '\n';
```

`pa` 可以当作 `ull` 数组使用。



### Bitset 可优化问题

1. DP 问题中，状态数组是 bool (例如布尔背包)
2. 需要做大量的集合取交集，并集的操作。
