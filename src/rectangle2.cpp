/*
这个是经典的DP问题，这里注意分为两个步骤来解决，将数据排序，得到一个递增的序列，第二步，将这个问题转化为最长单调递增子序列问题，通过上面的两步，问题也就解决了，这题已经AC，这里提供参考。
*/
#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
  
using namespace std;  
  
struct ans{  
    int x;  
    int y;  
};  
struct ans a[1001];  
int dp[1001];  
  
bool cmp(struct ans a,struct ans b)  
{  
    if(a.x <= b.x) return 1;  
    else if(a.x == b.x && a.y < b.y)  
    return 1;  
    else return 0;  
}  
  
bool max(struct ans m,struct ans n)  
{  
    if(m.x < n.x && m.y < n.y) return 1;  
    else return 0;  
}  
  
int main()  
{  
    int n,m,i,j,k;  
    scanf("%d",&n);  
    while(n--)  
    {  
        scanf("%d",&m);  
        for(i = 0; i < m; i++)  
        {  
            scanf("%d%d",&a[i].x,&a[i].y);  
            if(a[i].x > a[i].y)  
            {  
                int tmp = a[i].x;  
                a[i].x = a[i].y;  
                a[i].y = tmp;  
            }  
        }  
        sort(a,a+m,cmp);  
        memset(dp,0,sizeof(dp));  
        for(i = 1; i < m; i++)  
        {  
            for(j = 0; j <= i; j++)  
            {  
                if(max(a[j],a[i])&&dp[i] < dp[j] + 1)  
                {  
                    dp[i] = dp[j] + 1;  
                }  
            }  
        }  
        int max = dp[0];  
        for(i = 0; i < m; i++)  
        {  
            if(max < dp[i])  
            max = dp[i];  
        }  
        printf("%d\n",max+1);  
    }  
    return 0;  
}  