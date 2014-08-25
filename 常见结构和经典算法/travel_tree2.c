/*尝试用非递归重写树的遍历*/
/*先序遍历*/
void preorder_travel(tree T)
{
Stack s;
if(T!=NULL)
{
push(s,T);
while(!is_empty(s))
{
ptrnode temp;
temp=pop(s);
visit(temp);/*先访问节点*/
if(temp->rchild!=NULL)/*注意节点的入栈顺序为先右子树后左子树*/
push(s,temp->rchild);
if(temp->lchild!=NULL)
push(s,temp->lchild);
}
}
}

/*方法二，入栈之前访问，一直访问到底，然后弹出向又访问*/
void preorder_travel(tree T)
{
Stack s;
while(T!=NULL||!is_empty(s))
{
if(T!=NULL)
{
visit(T);
push(s,T->lchild);
T=T->lchild;
}
else/*左节点已经全部入栈，弹出，并向右进行这个过程*/
{
T=pop(s);
T=T->rchild;
}
}
}

/*中序遍历*/

