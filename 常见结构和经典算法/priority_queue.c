/*堆是至少允许插入和删除最小者二者操作的一种数据结构，在操作系统中有应用*/
struct heapstruct;
typedef struct heapstruct *heap;
struct heapstruct
{
int capacity;
int size;
elementtype *element;
};
heap init(int maxelement);
void  insert(elementtype x,heap h);/*往堆里插入一个元素*/
void delete_min(heap h);/*删除最小元素*/
void percolate_down(heap h,int i);/*节点的下滤*/
int is_full(heap h);
int is_empty(heap h);

int is_full(heap h)
{
return (h->capacity==h->size)?1:0;
}

int is_empty(heap h)
{
return (h->size==0)?1:0;
}

heap init(int maxelement)
{
heap h;
h=(heap)malloc(sizeof(struct heapstruct));
if(h==NULL)
fatalerror("out of space");
h->element=(element*)malloc(sizeof(elementtype)*maxelement);
if(h->element==NULL)
fatalerror("out of space");
h->size=0;
h->capacity=maxelement;
return h;
}

void delete_min(heap h)
{
if(is_empty(h))
fatalerror("queue is empty!");
elementtype minelement=h->element[1];/*此处注意*/
elementtype lastelement=h->element[h->size--];/*取得最后一个元素，同时将size减小1*/
h->element[1]=lastelement;/*将最后一个节点赋给第一个节点，同时进行调节*/
percolate_down(h,0);
return minelement;
}

void percolate_down(heap h,int i)
{
elementtype temp=h->element[i];
int k;
int child;
for(k=i;k*2<=h->size;k=child)
{
child=k*2;
if(child!=h->size&&h->element[child+1]<h->element[child])/*注意此处的判断，我们总是小心*/
child++;
if(h->element[k]>h->element[child])
h->element[k]=h->element[child];
else
break;
}
h->element[k]=temp;
}

void insert(elementtype x,heap h)/*采用上滤的插入,此处注意到的是我们0号元素并没有使用*/
{
if(is_full(h))
fatalerror("queue is full!");
int i;
for(i=++h->size;i>=2;i/=2)/*此处注意，我们同时将size增大了1，此处其实还有一个处理方法，就是将0号元素置得比所有可能值都小，那么元素最多会在1出停下*/
{
if(h->element[i/2]>x)
h->element[i]=h->element[i/2];
else
break;
}
h->element[i]=x;
}








