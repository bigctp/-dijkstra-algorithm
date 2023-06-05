#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 10000
int dist[6], prev[6];
int main()
{
    FILE *fp;
    int tu[6][6];
    int i,j,vs,min,location,temp,count=0,x;
    int flag[6];
    int path[6];
    fp=fopen("tu.txt","r");
    if(fp==NULL)
    {
        printf("The file data was not opened\n");
        exit(-1);
    }
    else
    {
        for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                fscanf(fp,"%d ",&tu[i][j]);
                printf("%d ",tu[i][j]);
            }
            printf("\n");
        }
    }
    printf("请输入起始结点：");
    scanf("%d",&vs);
    vs=vs-1;
    for (i = 0; i < 6; i++)
    {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = -1;              // 顶点i的前驱顶点为0。
        dist[i] = tu[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
        if(dist[i]<INF)
        {
            prev[i]=vs;
        }
    }
    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;
    for (i = 1; i < 6; i++)
    {
        min=INF;
        for(j=0; j<6; j++)
        {
            if(flag[j]==0&&dist[j]<min)
            {
                min=dist[j];
                location=j;
            }
        }
        flag[location]=1;
        for(j=0; j<6; j++)
        {
            temp=(tu[location][j]==INF?INF:(min+tu[location][j]));
            if(temp<INF&&temp<dist[j]&&flag[j]==0)
            {
                dist[j]=temp;
                prev[j]=location;
            }
        }
    }
    for (i = 0; i < 6; i++)
    {
        printf("Vex(%d) and Vex(%d)'s shortest path and consume:%d\n",vs+1, i+1, dist[i]);
        x=i;
        if(vs==x)
        {
            printf("%d-%d\n",vs+1,x+1);
        }
        else
        {
            count=0;
            while(vs!=x)
            {
                path[count++]=x+1;
                x=prev[x];
            }
            path[count]=x+1;
            for(j=count; j>0; j--)
            {
                printf("%d-",path[j]);
            }
            printf("%d\n",path[j]);
        }
    }
}
