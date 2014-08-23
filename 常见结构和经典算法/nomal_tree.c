/*树的应用很广，其大部分操作的平均时间是logN.下一系列面是对树的一个基本总结，首先是普通的树*/
/*我以树中元素为int为例子，当然它可以是任何用户自定义的类型*/
/*一个树节点的申明是如下所示的*/
typedef struct treenode *ptrnode;
typedef struct treenode *directory;
struct treenode
{
int element;
ptrnode lchild;
ptrnode sibling;
};/*由于树的孩子并不固定，所以使用sibling这一指针便可以表示任意的孩子了*/
/*在树中，我们最常进行的便是遍历操作，根据根节点访问的顺序，分为先序遍历,中序遍历(二叉树)以及后续遍历*/
/*以对文件系统的遍历为例子，这个文件系统是一颗树的结构，伪代码如下*/
/*首先是先序遍历，常用于打印文件结构中，它会首先打印出当前文件，如果文件是目录的话则会递归的打印目录下的文件*/
void list_dir(directory dir,int depth)
{
if(dir is legal)
{
print_name(dir,depth);
if(dir is a directory)
for every child ,c,of dir
list_dir(c,depth+1);
}
}
void list_directory(directory dir)
{
list_dir(dir,0);/*从根节点开始打印*/
}
/*逻辑很简单，先打印自己然后递归打印自己目录下的东西，加入一个depth是因为很多时候要求打印的时候有缩进，显然depth一样的缩进当然一样了*/
/*可以考察这个算法的效率是O(N)*/


/*然后是后续遍历，这种遍历有什么用呢？想象一下，如果我们想获得被这个文件夹所占据的磁盘总数。最简单的思维就是先获得这个文件夹下的文件的磁盘数目，然后加上自己的就是了。这种先孩子后自己便是后序遍历了*/
int size_of_dir(directory dir)
{
int totalsize=0;
if(dir is legal)
{
dir=filesize(dir);
if(dir is a directory)
for every child, c,of dir
totalsize+=size_of_dir(c);
}
return totalsize;/*在计算完孩子的大小后最后才得到自己的大小*/
}
/*可以看到如果dir不是一个目录的话，它就会只返回自己的大小*/


