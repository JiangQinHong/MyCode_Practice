/*散列表的实现,散列表是一种以常数平均时间进行查找，插入，删除的技术，但是任何有关排序的操作都不会得到实现*/
/*分离链接法，对于有冲突的元素，用链表链接在后面*/
struct listnode;
typedef struct listnode *position;
struct hash;
typedef struct hash *hashtable;
struct listnode
{
elementtype element;
position next;
};

struct hash
{
int tablesize;
position *list;/*由position这种类型指针组成的数组,list是一个指向指针的指针*/
};
/*支持的基本操作*/
void insert(elementtype key,hashtable h);
void search(elementtype key,hashtable h);
hashtable init(int tablesize);
void destory(hashtable h);
/*==========*/
hashtable init(int tablesize)
{
hashtable h;
h=(hashtable)malloc(sizeof(struct hash));
if(h==NULL)
fatalerror("out of space");
h->list=(position*)malloc(tablesize*sizeof(struct listnode));
if(h->list==NULL)
fataerror("out of space");
h->tablesize=tablesize;
int i;
for(i=0;i<h->tablesize;i++)
{
h->list[i]->next=NULL;
h->list[i]->element=flag;
}
return h;
}
/*insert 操作*/
void insert(elementtype key,hashtable h)
{
int index;
index=hash(key,h->tablesize);/*通过设定的hash函数来获取下标值*/
position temp;
temp=h->list[index];
if(temp->element==flag)/*第一个节点尚未被使用*/
{
temp->element=key;
}
else/*已经被使用*/
{
while(temp!=NULL)
{
if(temp->element==key)
break;
temp=temp->next;
}
if(temp==NULL)/*没有找到相同的节点,则把它放在第一个节点*/
{
position insert;
insert=(position)malloc(sizeof(struct listnode));
insert->element=key;
insert->next=h->list[index];
h->list[index]=insert;
}
}
}

position search(elementtype key,hashtable h)
{
int index;
index=hash(key,h->tablesize);
position temp;
temp=h->list[index];
while(temp!=NULL)
{
if(temp->element==key)
break;
temp=temp->next;
}
return temp;/*找到了则返回这个节点指针，否则就返回NULL*/
}

void destory(hashtable h)
{
int i;
position temp,post;
for(i=0;i<h->tablesize;i++)
{
temp=h->list[i];
while(temp!=NULL)
{
post=temp->next;
free(temp);
temp=post;
}
}
}
/*至此分离链接法构造的散列表完成，注意的是在这种方法中填充因子最好接近于1，也就是表的大小最好接近与预料的元素个数，同时使得表的大小为一个素数*/


/*开放地址法*/
typedef struct hash *hashtable;
typedef struct node cell;
typedef int index;
struct hash
{
int tablesize;
cell *cells;
};
struct node
{
elementtype element;
int flag;
};
#define empty 0
#define deleted 1 
#define occupyed 3

hashtable init(int tablesize);
void insert(elementtype key,hashtable h);
index find(elementtype key,hashtable h);
void destory(hashtable h);

hashtable init(int tablesize)
{
hashtable h;
h=(hashtable)malloc(sizeof(struct hash));
if(h==NULL)
fatalerror("out of space");
h->cells=(cell*)malloc(sizeof(struct cell)*tablesize);
if(h->cells==NULL)
fatalerror("out of space");
h->tablesize=tablesize;
int i;
for(i=0;i<tablesize;i++)
h->cells[i].flag=empty;
return h;
}

/*插入,开放地址法中除了hash函数的选择外还要考虑发生冲突后采取怎样的探测策略，是线性探测还是平方探测，或者其它探测方法*/
/*不写了，差不多*/













