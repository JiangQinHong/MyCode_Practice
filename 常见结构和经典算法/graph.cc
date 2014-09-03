/*拓扑排序*/
#include<stdlib.h>
#include<stdio.h>
typedef class node *gnode;
typedef gnode *graph;//指向指针的指针
typedef int vertex;
struct node{
	vertex value;
	gnode next;
};

typedef struct table_entry{//table_entry是一个更复杂一点的邻接表的头结构,它捎带了额外的信息,放在一个数组中,而每一个和它邻接的节点
	           //则通过header链接起来
	gnode header;
	int known;
	int distance;
	vertex path;
}table_entry;
typedef table_entry *table;
//拓扑排序
//将一个入度为零的点入队,出队的同时,将所有邻接的点入度减少1,将新的入度为0的点加入队列,递归操作
int topnum[num_vertex];//用来保存拓扑序号,注意的时数组下标和编号对应
int indegree[num_vertex];//用来保存每个顶点的入度,当然最简便的方法时将入度放到临接表的头单元中
//我们假设已经将图读入到了一个邻接表中
void top_sort(graph G)
{
	queue q;//建立一个队列
	int counter=0;//计数当前top号
	gnode v,w;
	q=create_queue(num_vertex);
	make_empty(q);
	for each gnode v
		if(indegree==0)
			enqueue(v,q);
	while(!is_empty(q))
	{
		v=dequeue(q);
		topnum[v]=++counter;
		for each w adjacent to v
			if(--indegree[w]==0)
				enqueue(w,q);
		if(counter>num_vertex)
			break;

	}
	if(counter!=num_vertex)
		printf("there is a circle!");
	dispose_queue(q);
}
//上面的算法还可以用来检验一个给出的有向图是否有圈

/*然后时最短路径算法,最短路径分为有赋权的和无权的,无权的采用一个广度优先搜索可以实现.如果出现负值圈的话这个问题将变
  *得复杂,无权图的最短路径寻找操作很像一个拓扑排序,只不过判断的条件不一样*/
void unweighted(table t,gnode start)
{
	queue q;
	gnode v,w;
	q=create_queue(q);
	makeempty(q);
	enqueue(start,q);
	while(!empty(q))
	{
		v=dequeue(q);
		t[v].known=true;
		for each w adjacent to v
			if(t[w].distance==infinity)
			{
				t[w].distance=t[v].distance+1;
				t[w].previous=v;
				enqueue(w);
			}
	}
	dispose_queue(q);
}

/*然后时赋权图,它将会复杂一些*/
/*我们先定义一个table的结构,免得使数据结构变得冗长*/
//首先时将数据读入
void init_table(vertex start,graph g,table t)
{
	int i;
	read_graph(g,t);
	for(i=0;i<num_vertex;i++)
	{
		t[i].known=false;
		t[i].distance=infinity;
		t[i].path=not_vertex;
	}
	t[start].distance=0;
}

void dijkstra(table t)
{
	vertex v,w;
	while(1)
	{
		v=find_smallest_unknown_vertex(t);
		if(v==not_vertex)
			break;
		t[v].known=true;
		for each w adjacent to v
			if(!t[w].known)
				if(t[v].distance+value<t[w].distance)
				{
					decrease(t[w].distance to t[v].distance+value);
					t[w].path=v;
				}
	}
}//value 为两点间的消耗,我们可以将它放在链表中的链接节点内

void print_path(vertex start,table t)
{
	if(t[start].path!=not_vertex)
	{
	print_path(t[start].path);
	printf("to");
	}
	printf("%d",start);
}
//递归打印出这条路径

/*无向图应用*/
/*然后时网络流问题*/
/*然后是最小生成树问题,出名的有prim算法以及kruskal算法*/
/*prim算法是每次选和当前集合点链接的最小边,然后将顶点链接进来,而kruskal则是每次选择最小边,直到所有顶点都联通*/
/*一个kruskai算法的伪代码是这样的*/
void kruskal(graph g)
{
	int edge_accepted=0;//用来记录当前收录了多少条边,一共需要收录顶点数减一条边
	disjset s;
	heap h;//用堆来保存边可以每次delete_min删除堆顶元素即可
	vertex u,v;
	settype uset,vset;//集合,用来判断一条边的两节点是否在同一集合中
	edge e;
	init(s);
	read_graph_to_heap(g,h);
	buildheap(h);
	while(edge_accepted<num_vertex-1)
	{
		e=deletemin(h);//一条边包含(u,v)两个顶点
		uset=find(e.u,s);
		vset=find(e.v,s);
		if(uset!=vset)
		{
			edge_accepted++;
			set_union(s,uset,vset);//将这两个集合合并
		}
	}
}
















