typedef int * disjoint_set;
typedef int set_type;
typedef int element_type;
void init(disjoint_set);
void set_union(disjoint_set s,set_type root1,set_type root2);
void find(element_type x,disjoint_set s);


void init(disjoint_set s)
{
	int i;
	for(i=num_of_sets;i>0;i--)
		s[i]=0;
}

void set_union(disjoint_set s,set_type root1,set_type root2)
{
	if(s[root2]<s[root1])
		s[root1]=root2;//将根节点保存一个负值,显示为树的深度
	else
	{
		if(s[root1]==s[root2])
			s[root1]--;
		s[root2]=root1;
	}
}

set_type find(element_type x,disjoint_set s)
{
	if(s[x]<=0)
		return x;
	else
		return s[x]=find(s[x],s);
}//注意的是,这里的find包含了路径压缩操作



