#include<stdio.h>
int main()
{
	int result,input;
	char deal;
	scanf("%d%c",&input,&deal);
	result=input;
	while(deal!='=')
	{
		scanf("%d",&input);
		switch(deal){
		case'+':
			result+=input;
			break;
		case'-':
			result-=input;
			break;
		case'*':
			result*=input;
			break;
		case'/':
			if(input==0)
			{
				printf("除法分母不能为零！");
				return 0;
			}
			result/=input;
			break;
		default:
			printf("非运算符，不允许！");
			return 0;
		}
		scanf("%c",&deal);
	}
	printf("%d\n",result);
	return 0;
}