#include <stdio.h>
#define F 10
int main(int argc, const char * argv[]) {
    int N,f=1,h=0,l=0,one,two,three,four,i,C,c;
    int fz[F][F];
    scanf("%d",&N);
    one=N;two=N-1;three=N-1;four=N-2;
    if(N%2==0)
        C=N/2;
    if(N%2!=0)
        C=(N-1)/2+1;
    for(c=1;c<=C;c++)
    {
        for(i=1;i<=one;i++)
        {
            fz[h][l]=f;
            f++;
            l++;
        }
        l--;
        h++;
        for(i=1;i<=two;i++)
        {
            fz[h][l]=f;
            f++;
            h++;
        }
        h--;
        l--;
        for(i=1;i<=three;i++)
        {
            fz[h][l]=f;
            f++;
            l--;
        }
        l++;
        h--;
        for(i=1;i<=four;i++)
        {
            fz[h][l]=f;
            f++;
            h--;
        }
        l++;
        h++;
        one=one-2;two=two-2;three=three-2;four=four-2;
    }
    for(h=0;h<=N-1;h++)
    {
        for(l=0;l<=N-1;l++)
            printf("%d ",fz[h][l]);
        printf("\n");
    }
    return 0;
}
