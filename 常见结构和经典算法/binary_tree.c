/*二叉树有两个儿子，所以可以直接由根节点指向它们即可*/
typedef struct tree_node *ptrnode;
typedef struct tree_node *tree;
struct tree_node
{
int element;
ptrnode lchild;
ptrnode rchild;
}/*二叉树结构清晰，分别指向左右孩子即可，当然也可用数组实现，不过指针比较清晰，我采取指针*/
/*二叉树的应用之一---表达式树*/
/*通过后缀表达式构造一颗表达式树*/
/*其策略为如果为操作数，则进栈，如果为操作符，则弹出两个元素，指向该操作符，将该操作符进栈*/
tree create_expression_tree()
{
char in;
stack store;/*这是一个树节点指针类型的栈，用于存储*/
while((in=getchar())!=EOF)
{
ptrnode new_node=create_tree_node(in);/*创建一个节点*/
if in is operand
push(new_node,store);
if in is operator
{
new_node->rchild=pop(store);
new_node->lchild=pop(store);
push(new_node,store);
}
}
}
/*至此一棵表达式树构造完成*/

/*接下来是二叉树中非常重要的一个应用，二叉查找树，其在查找中有着很重要的应用，因为其平均深度为logN*/
/*二叉查找树是左子树关键字小于节点，右子树关键字大于节点的树，很明显这是一个递归定义*/
/*对二叉查找树进行的操作有创建一颗空树，查找，查找最大，查找最小，删除，插入，下面一一定义*/
tree make_empty(tree T)
{
if(T!=NULL)
{
make_empty(T->lchild);
make_empty(T->rchild);
free(T);
}
return NULL;
}

/*find,find_min,find_max*/
ptrnode find(int x,tree T)
{
if(T==NULL)
return NULL;
if(x<T->element)
return find(T->lchild);
if(x>T->element)
return find(T->rchild);
else
return T;
}

ptrnode find_min(tree T)
{
if(T==NULL)
return NULL;
else
if(T->lchild==NULL)
return T;
else
return find_min(T->lchild);
}

ptrnode find_max(tree T)
{
if(T==NULL)
return NULL;
else
if(T->rchild==NULL)
return T;
else
return find_max(T->rchild);
}
/*当然完全不用使用递归，使用递归是为了让结构更加清晰*/
/*insert*/
tree insert(int x,tree T)
{
if(T==NULL)
{
T=(tree)malloc(sizeof(struct tree_node));
T->element=x;
T->lchild=NULL;
T->rchild=NULL;
}
else
if(x<T->element)
T->lchild=insert(x,T->lchild);
else
if(x>T->element)
T->rchild=insert(x,T->rchild);
return T;
}
/*注意到如果x相等的话，我们什么也不做*/
/*delete操作，这个操作稍微麻烦一点，删除过后我们应该寻找左边的最大节点或者右边的最小节点来替换当前节点，然后递归的删除*/
tree delete(int x,tree T)
{
if(T==NULL)
Error("not found");
else
if(x<T->element)
T->lchild=delete(x,T->lchild);
else
if(x>T->element)
T->rchild=delete(x,T->rchild);
else/*找到了*/
{
if(T->lchild&&T->rchild)/*拥有两个孩子*/
{
ptrnode temp;
temp=find_min(T->rchild);
T->element=temp->element;
T->rchild=delete(temp->element,T->rchild);
}
else/*只有一个孩子*/
{
if(T->lchild==NULL)
T=T->rchild;
if(T->rchild==NULL)
T=T->lchild;
}
}
return T;
}
/*注意到为了保持程序易读，后面进行了两次遍历，效率并不高。当然这很容易改进*/

