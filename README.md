# shuffle-algorithm

## 问题描述

洗牌算法指的是将一个序列打散，生成一个新的随机排列，英文描述如下：

[Fisher-Yates shuffle](https://en.wikipedia.org/wiki/Fisher–Yates_shuffle): The **Fisher–Yates shuffle** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for generating a [random permutation](https://en.wikipedia.org/wiki/Random_permutation) of a finite [sequence](https://en.wikipedia.org/wiki/Sequence)—in plain terms, the algorithm [shuffles](https://en.wikipedia.org/wiki/Shuffling) the sequence. 

## Fisher-Yates Shuffle算法

### 算法描述

最原始的洗牌算法，中心思想为从原数组中随机抽出一个数加入到新数组中，并将该数从原数组中删除。用于生成1～N的随机排列算法如下：

~~~
1. Write down the numbers from 1 through N.
2. Pick a random number k between one and the number of unstruck numbers remaining (inclusive).
3. Counting from the low end, strike out the kth number not yet struck out, and write it down at the end of a separate list.
4. Repeat from step 2 until all the numbers have been struck out.
5. The sequence of numbers written down in step 3 is now a random permutation of the original numbers.
~~~

时间复杂度：O(n^2)

空间复杂度：O(n)

### 算法证明

P(原数组中元素m（1<=m<=n）被放在新数组中第i个位置) = P(前i-1次随机选取都没有选中m) * P(第i次随机选取选中m)，即：$$P = \frac{n-1}{n}\frac{n-2}{n-1}...\frac{n-i+1}{n-i+2}\frac{1}{n-i+1} = \frac{1}{n}$$

## **Knuth-Durstenfeld Shuffle** 

### 算法描述

基于原始洗牌算法的改进版本，中心思想为不新建数组，每次从数组中随机选出一个数，加入到数组尾部，数组尾部为随机排列的数字。算法描述如下：

~~~
1. 数组arr存放1～n
2. 生成一个0～n-1的随机数pos
3. 将arr[pos]与arr[n-1]交换
4. 同2，生成一个从0到n-2的随机数pos
5. 将arr[pos]与arr[n-2]交换
.....
直到有n个数交换到了数组末尾
~~~

时间复杂度：O(n)

空间复杂度：O(1)

### 算法证明

对于arr[i]（0<=i<=n-1），洗牌后在各位置概率如下：

1. P(交换到arr[n - 1]) = 1 / n（第一次生成的随机数为i）
2. P(交换到arr[n  -2]) = $$\frac{n-1}{n}\frac{1}{n-1}=\frac{1}{n}$$（第一次随机数没有选中i并且第二次随机数选中i。对于i=n-1，第一次未选中表明arr[i]交换到arr[0]...arr[n-2]中间，第二次选中再将其交换到arr[n-2]）
3. P(交换到arr[n-k]) = $$\frac{n-1}{n}\frac{n-2}{n-1}...\frac{n-k+1}{n-k+2}\frac{1}{n-k+1}=\frac{1}{k}$$

##Inside-Out Algorithm

### 算法描述

相较于Knuth-Durstenfeld Shuffle，有时需要保持原始数据，所以开辟一个新数组存储。中心思想为从前向后扫描数据，对于a[i]，生成0~i的随机数pos，然后交换a[i]，a[pos]。

Inside-Out Algorithm可以由前向后扫描数组，所以可以应该arr[]数目未知或者动态增加的情况。算法描述如下：

~~~
1. 生成一个新数组arr_t[]，复制arr[]
2. 生成一个0～0的随机数pos
3. 将arr_t[0]与arr_t[j]交换
4. 同2，生成一个从0～1的随机数pos
5. 将arr_t[pos]与arr_t[1]交换
.....
生成一个0～n-1的随机数pos
将arr_t[pos]与arr_t[n-1]交换
直到有n个数交换到了数组末尾
~~~

时间复杂度：O(n)

空间复杂度：O(n)

### 算法证明

对于arr[i]（0<=i<=n-1），洗牌后在各位置概率如下：

1. P(交换到arr[0]...arr[i]) = $$\frac{1}{i+1}\frac{i+1}{i+2}...\frac{n-1}{n}=\frac{1}{n}$$
2. P(交换到arr[i+1]) = $$\frac{1}{i+2}\frac{i+2}{i+3}...\frac{n-1}{n}=\frac{1}{n}$$
3. P(交换到arr[i+k]) = $$\frac{1}{i+k+1}\frac{i+k+1}{i+k+2}...\frac{n-1}{n}=\frac{1}{n}$$

## 蓄水池抽样(Reservoir_Sampling)

###  算法描述

从n个元素中随机等概率选出k个数。

先选中第1到k个元素，作为被选中的元素。然后依次对k+1~N个元素做如下操作：生成1～i的随机数，i$\in$[k+1,N]，若i<=k，则将第i个元素和第k个元素替换。

### 算法证明

参考https://blog.csdn.net/qq_26399665/article/details/79831490，写的非常好。

