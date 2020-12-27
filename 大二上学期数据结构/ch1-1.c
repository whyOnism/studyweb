#include<stdio.h>
#define N 5
void main()
{
int arr[N][N]={0};
int i=0,j=0;
int key,k; 
int num=1; 
key = N-1;
for(key=N-1; key>0; key -= 2)
{
for (k=0; k<key; ++k)
{
arr[i][j] = num;
++i;
++num;
}
for (k=0; k<key; ++k)
{
arr[i][j] = num;
++j;
++num;
}
for (k=0; k<key; ++k)
{
arr[i][j] = num;
--i;
++num;
}
for (k=0; k<key; ++k)
{
arr[i][j] = num;
--j;
++num;
}
++i;
++j;
}
if(0==key)
arr[i][j]=num;
for(i=0; i<N; ++i)
{
for(j=0; j<N; ++j)
printf("%3d",arr[i][j]);
printf("\n");
}
}

