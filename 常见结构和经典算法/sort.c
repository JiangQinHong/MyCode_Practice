/*对排序算法的总结*/
/*首先是插入排序,它基于位置0到p-1上已经排好序的事实*/
void insert_sort(elementtype A[],int N)
{
int i,j;
int temp;
for(i=1;i<N;i++)
{
temp=A[i];
for(j=i;j>0;j--)
{
if(A[j-1]>temp)/*一一比较，如果比temp大则往后腾出一个坑来*/
A[j]=A[j-1];
else
break;
}
A[j]=temp;
}
}

/*然后是最简单的冒泡排序，它每次将最大的一个元素放到相应的最后*/
void bubble_sort(elementtype A[],int N)
{
int i,j;
int temp;
for(i=N-1;i>0;i--)
for(j=0;j<i;j++)
{
if(A[j+1]<A[j])
{
temp=A[j+1];
A[j+1]=A[j];
A[j]=temp;
}
}
}

/*然后是希尔排序，它其实也是一种插入排序，不过所选的增量序列不是1，但最终增量序列必须为1*/
void shell_sort(elementtype A[],int N)
{
int i,j,increment;
int temp;
for(increment=N/2;increment>0;increment/=2)/*插入排序即是increment=1时候的排序*/
for(i=increment;i<N;i++)
{
temp=A[i];
for(j=i;j>increment;j-=increment)
{
if(A[j-increment]>temp)
A[j]=A[j-increment];
else
break;
}
A[j]=temp;
}
}

/*然后是堆排序，堆排序中我们发现并不需要额外的开辟空间，因为可以将最后一个空位用来填首节点删除的节点，我们建立一个最大堆，一次次删除后便可以得到一个排好序的数组了*/
void heap_sort(elementtype A[],int N)
{
int i;
for(i=N/2;i>=0;i--)
percdown(A,i,N);
for(i=N-1;i>0;i--)/*只需要将首尾节点交换，然后重新调节堆即可*/
{
swap(&A[0],&A[i]);
percdown(A,0,i-1);
}
}

void percdown(elementtype A[],int i,int N)
{
int parent,child;
elementtype temp;
int k;
temp=A[i];
parent=i;
child=2*i+1;
while(child<N)
{
if(child!=N-1&&A[child+1]>A[child])
child++;
if(A[child]>temp)
A[parent]=A[child];
else
break;
parent=child;
child=child*2+1;
}
A[parent]=temp;
}

/*然后是归并排序，归并排序的原理是假设左右两个子序列都已排好序，则只需将它们合并起来即可，这是一种分治的思想*/
void merge_sort(elementtype A[],int N)
{
elementtype *temparray;
temparray=(elementtype*)malloc(sizeof(struct elementtype)*N);
if(temparray==NULL)
fatalerror("no space for merge_sort");
else
{
msort(A,temparray,0,N-1);
free(temparray);
}
}

void msort(elementtype A[],elementtype temparray[],int left,int right)
{
int center;
if(left<center)/*递归结束条件为左边等于右边*/
{
center=(left+right)/2;
msort(A,temparray,left,center);/*将左边排序*/
msort(A,temparray,center+1,right);/*将右边排序*/
merge(A,temparray,left,center+1,right);/*将左右归并,其中排序也体现在里面*/
}
}

void merge(elementtype A[],elementtype temparray[],int lbegin,int rbegin,int rend)
{
int lend=rbegin-1;
int number=rend-lbegin+1;
int temp=lbegin;
while(lbegin<=lend&&rbegin<=rend)
{
if(A[lbegin]>=A[rbegin])
{
temparray[temp++]=A[rbegin++];
}
else
temparray[temp++]=A[lbegin++];
}
while(lbegin<=lend)
temparray[temp++]=A[lbegin++];
while(rbegin<=rend)
temparray[temp++]=A[rbegin++];
int i;
for(i=0;i<number;i++)
A[rend--]=temparray[rend--];
}

/*最后是快排，快排每次选定一个pivot，将数组中所有大于它的元素放到它左边，小于它的放到它右边，然后对左右再分别这样递归*/
/*关键点之一是pivot的选取*/
void quick_sort(elementtype A[],int left,int right)
{
if(left<right)
{
int i=left;
int j=right;
int pivot=A[left];
while(left<right)
{
while(i<j&&A[j]>=pivot)
j--;
if(i<j)
A[i++]=A[j];
while(i<j&&A[i]<=pivot)
i++;
if(i<j)
A[j--]=A[i];
}
A[i]=temp;
}
quick_sort(A,left,i-1);
quick_sort(A,i+1,right);
}

void sort(elementtype A[],int N)
{
quick_sort(A,0,N-1);
}

