#include "stdio.h"
#include "string.h" 
#define maxn 1000+10 

typedef struct {		//矩形的数据结构，长、宽 
	int length;	
	int width;
}rectangle;

int G[maxn][maxn]; 		//DAG图的矩阵表示 
int d[maxn],n;			//d[i]顶点i的最长路径 
rectangle rec[maxn];

//打印出图的邻接矩阵，目的是确保建图正确无误 
void print_Graph()
{
	printf("|矩 形|");
	for(int i=0;i<n;i++) 
		printf("%2d,%2d|",rec[i].length,rec[i].width);
	printf("\n");
	
	for(int i=0;i<n;i++){
		for(int k=0;k<=n;k++)
			printf("------");
		printf("\n");
		
		printf("|%2d,%2d|",rec[i].length,rec[i].width);
		for(int j=0;j<n;j++){
			printf("  %d  |",G[i][j]);
		}printf("\n");
		
	}	
}


//构造图 
void createGraph()
{
	memset(G,0,sizeof(G));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(rec[i].length>rec[j].length && rec[i].width>rec[j].width){				
				G[i][j]=1; 	//rec[i] 包含 rec[j]
			}
		}
	}
	
//	print_Graph();
}

//记忆化搜索程序 
int dp(int i)
{
	int& ans=d[i];	//为该表项声明一个引用，简化对它的读写操作。 
	if(ans>0) return ans;
	ans=1;
	for(int j=0;j<n;j++){
		if(G[i][j]){
			int tmp=dp(j);
			ans=ans>tmp+1?ans:tmp+1; 
		}
	}
	return ans;
}

int main()
{
	int N;
	scanf("%d",&N);
	while(N-->0)
	{
		int ans=0;
		scanf("%d",&n); 
		for(int i=0;i<n;i++){
			int tmp1,tmp2;
			scanf("%d%d",&tmp1,&tmp2);
			rec[i].length=tmp1>tmp2?tmp1:tmp2;
			rec[i].width=tmp1<tmp2?tmp1:tmp2; 
		}
		createGraph();
		
		//初始化记忆数组 
		memset(d,0,sizeof(d)); 
		for(int i=0;i<n;i++){
			int tmp=dp(i);
			ans=ans>tmp?ans:tmp;	
		}
		printf("%d\n",ans);
	} 
	return 0;
}