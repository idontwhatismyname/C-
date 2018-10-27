����Tower of Hanoi�����㷨�Ľ��ͺͽ���
===========================
## �ݹ�
### �ֽ�����:   
����n��disk�ŵ�peg C�ֽ�Ϊ��n-1��disk�ŵ�peg B ...    
...һֱ��n=1��ʱ��
### ���ڵݹ�ľ������:  
```
��ǰn-1��disk��peg 1�ŵ���peg 2��  
Ȼ�󽫵�n���ŵ�peg 3��  
�ٽ�ǰn-1��disk��peg 2�ŵ�peg 3
```
�õݹ�ı߽���n=1

## ѭ��
### ����ѭ�������������  

����ֻ������peg����peg֮��Ĳ���ֻ����������ѭ��ʵ����ֻ����������������ѭ����  
���ң�Ϊ�������������

```
���迪ʼʱpeg 1��12345��peg 2��peg 3����0
1->3 1->2 3->1 1->2
��ʱ���Կ������������������1��ʵ���ȴ�3��1�ٴ�1��2���൱��ʵ�е���3->2
```
������ѭ������ͨ��������������һ��˳����У�ֱ�����  

���ɵ�һ�ַ���`�ݹ�`���ǿ��Ե�֪��ѭ�������ܹ���Ҫ<a href="http://www.codecogs.com/eqnedit.php?latex=2^{n}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?2^{n}" title="2^{n}" /></a>-1
�Σ���ѭ������Ҳ��<a href="http://www.codecogs.com/eqnedit.php?latex=2^{n}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?2^{n}" title="2^{n}" /></a>-1

### ��������ѭ���ľ��������
* ����������n��disk��
```
peg A��peg B֮��ĺϷ��ƶ�����
peg A��peg C֮��ĺϷ��ƶ�����
peg B��peg C֮��ĺϷ��ƶ�����
һֱѭ�������
```
*ע��ÿ����������Ψһ��*
- ����ż����n��disk:
```
peg A��peg C֮��ĺϷ��ƶ�����
peg A��peg B֮��ĺϷ��ƶ�����
peg B��peg C֮��ĺϷ��ƶ�����
һֱѭ�������
```
Ϊ�˴���ļ���ԣ���ʹ���˲���������B��C���н���
#### ���ںϷ��ƶ��������ж�
```
������������`����`�����ʱ����peg�����е�����
��ͨ��a,b,c������`����`ȥ�ֱ𴢴��ʱpeg A peg B peg C�ϵ�disk��Ŀ
ͨ��`if���`ȥ�ж�����֮��ĺϷ�����
```

## Binary Operation
*ע���һ�û�и㶮����㷨��ԭ���ʴ�Wikipedia��ժ¼����ز�������˵��*

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
  - Also assume "wrapping" �C so the right peg counts as one peg "left" of the left peg, and vice versa.
  * Let n be the number of greater disks that are located on the same peg as their first greater disk and add 
  1 if the largest disk is on the left peg. If n is even, the disk is located one peg to the right, if n is odd, 
  the disk located one peg to the left (in case of even number of disks and vice versa otherwise).