对于Tower of Hanoi三种算法的解释和介绍
===========================
## 递归
### 分解问题:   
将把n个disk放到peg C分解为将n-1个disk放到peg B ...    
...一直到n=1的时候
### 关于递归的具体操作:  
```
将前n-1个disk从peg 1放到第peg 2里  
然后将第n个放到peg 3里  
再将前n-1个disk从peg 2放到peg 3
```
该递归的边界是n=1

## 循环
### 关于循环的问题解析：  

由于只有三个peg，则peg之间的操作只有三个。故循环实际上只是在这三个操作中循环。  
并且，为避免如下情况：

```
假设开始时peg 1是12345，peg 2和peg 3都是0
1->3 1->2 3->1 1->2
这时可以看到在最后两个操作中1其实是先从3到1再从1到2，相当于实行的是3->2
```
故我们循环这是通过这三个操作按一定顺序进行，直至完成  

而由第一种方法`递归`我们可以得知，循环次数总共需要<a href="http://www.codecogs.com/eqnedit.php?latex=2^{n}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?2^{n}" title="2^{n}" /></a>-1
次，故循环次数也是<a href="http://www.codecogs.com/eqnedit.php?latex=2^{n}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?2^{n}" title="2^{n}" /></a>-1

### 接下来是循环的具体操作：
* 对于奇数的n个disk：
```
peg A与peg B之间的合法移动操作
peg A与peg C之间的合法移动操作
peg B与peg C之间的合法移动操作
一直循环到完成
```
*注：每个操作都是唯一的*
- 对于偶数的n个disk:
```
peg A与peg C之间的合法移动操作
peg A与peg B之间的合法移动操作
peg B与peg C之间的合法移动操作
一直循环到完成
```
为了代码的简洁性，我使用了布尔变量对B与C进行交换
#### 对于合法移动操作的判断
```
我是利用三个`数组`储存此时三个peg所含有的数字
并通过a,b,c这三个`变量`去分别储存此时peg A peg B peg C上的disk数目
通过`if语句`去判断他们之间的合法操作
```

## Binary Operation
*注：我还没有搞懂这个算法的原理，故从Wikipedia上摘录了相关操作及其说明*

Disk positions may be determined more directly from the binary (base-2) representation of the move number (the initial state being move #0, with all digits 0, and the final state being with all digits 1), using the following rules:
- There is one binary digit (bit) for each disk.  
- The most significant (leftmost) bit represents the largest disk. A value of 0 indicates that the largest disk is   
on the initial peg, while a 1 indicates that it's on the final peg (right peg if number of disks is odd and  
middle peg otherwise).  
- The bitstring is read from left to right, and each bit can be used to determine the location of the  
corresponding disk.
- A bit with the same value as the previous one means that the corresponding disk is stacked on top 
the  previous disk on the same peg.    
_(That is to say: a straight sequence of 1s or 0s means that the corresponding disks are all on the same  
peg.)_  
- A bit with a different value to the previous one means that the corresponding disk is one position to the  
left or right of the previous one. Whether it is left or right is determined by this rule:  
  - Assume that the initial peg is on the left.
  - Also assume "wrapping" – so the right peg counts as one peg "left" of the left peg, and vice versa.
  * Let n be the number of greater disks that are located on the same peg as their first greater disk and add 
  1 if the largest disk is on the left peg. If n is even, the disk is located one peg to the right, if n is odd, 
  the disk located one peg to the left (in case of even number of disks and vice versa otherwise).  

