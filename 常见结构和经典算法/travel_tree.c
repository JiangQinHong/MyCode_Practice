/*树的遍历*/
/*先序遍历,可以利用节点深度标志出信息，常用于打印文件输出等 ，用二叉树作为特例*/
/*先给出树的结构*/
typedef struct node *ptrnode;
typedef struct node *tree;
struct node
{
int element;
ptrnode lchild;
ptrnode rchild;
};

/*先序遍历*/
void preorder_travel(tree T)
{
if(T!=NULL)
{
visit(T);
preoder_travel(T->lchild);
preoder_travel(T->rchild);
}
}

/*中序遍历,在二叉查找树中，这种遍历能够很容易解决关键字排序输出的问题*/
void midorder_travel(tree T)
{
if(T!=NULL)
{
midorder_travel(T->lchild);
visit(T);
midorder_travel(T->rchild);
}
}
/*后序遍历,后续遍历常用于计算值当中，比如我们计算表达式树的值,计算树的高度*/
void lastorder_travel(tree T)
{
if(T!=NULL)
{
lastoeder_travel(T->lchild);
lastorder_travel(T->rchild);
visit(T);
}
}
/*计算高度*/
int height(tree T)
{
if(T==NULL)
return -1;
else
return 1+max(height(T->lchild),height(T->rchild));
}

/*层序遍历*/
/*与前三种不同，栈已经不适合了，应该采用队列,当然就不是递归了*/
void level_travel(tree T,queue Q)
{
Q.Enqueue(T);
while(!is_empty(Q))
{
ptrnode temp;
temp=Q.Dequeue();
visit(temp);
if(temp->lchild!=NULL)
Q.Enqueue(temp->lchild);
if(temp->rchild!=NULL)
Q.Enqueue(temp->rchild);
}
}

/*可以看到的是，这几个操作的时间复杂度都是O(N),因为我们对每个节点都访问了一次，而每次访问时所做的操作都是常数时间*/

