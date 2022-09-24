#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>

#define NUM 10000

double gettime(struct timeval* begin,struct timeval* end){
    return (end->tv_usec-begin->tv_usec);
}

struct block
{
    int pad[64];
    int pad2[64];
    int pad3[63];
    int val=1;
};



int main(){
    long long int sum=0;
    long long int sum2=0;
    long long int sum3=0;
    long long int sum4=0;
    struct timeval begin,end;
    int* a=(int*)malloc(sizeof(int)*NUM);
    int* b=(int*)malloc(sizeof(int)*NUM);
    memset(a,1,sizeof(a));
    memset(b,1,sizeof(b));
    gettimeofday(&begin,NULL);
    // for (int i = 0; i < 10000; i++)
    // {
    //     __builtin_prefetch(&a[i+1]);
    //     __builtin_prefetch(&b[i+1]);
    //     sum+=a[i]+b[i];
    //     sum2+=a[i]+b[i];
    //     sum3+=a[i]+b[i];
    //     sum4+=a[i]+b[i];
    // }

    // for (int i = 0; i < 10000; i+=4)
    // {
    //     __builtin_prefetch(&a[i+4],0);
    //     __builtin_prefetch(&b[i+4],0);
    //     __builtin_prefetch(&a[i+5],0);
    //     __builtin_prefetch(&b[i+5],0);
    //     __builtin_prefetch(&a[i+6],0);
    //     __builtin_prefetch(&b[i+6],0);
    //     __builtin_prefetch(&a[i+7],0);
    //     __builtin_prefetch(&b[i+7],0);
    //     sum+=a[i]+b[i];
    //     sum+=a[i+1]+b[i+1];
    //     sum+=a[i+2]+b[i+2];
    //     sum+=a[i+3]+b[i+3];
    //     sum2+=a[i]+b[i];
    //     sum2+=a[i+1]+b[i+1];
    //     sum2+=a[i+2]+b[i+2];
    //     sum2+=a[i+3]+b[i+3];
    //     sum3+=a[i]+b[i];
    //     sum3+=a[i+1]+b[i+1];
    //     sum3+=a[i+2]+b[i+2];
    //     sum3+=a[i+3]+b[i+3];
    //     sum4+=a[i]+b[i];
    //     sum4+=a[i+1]+b[i+1];
    //     sum4+=a[i+2]+b[i+2];
    //     sum4+=a[i+3]+b[i+3];
    // }

    // for (int i = 0; i < 10000; i++)
    // {
    //     __builtin_prefetch(&a[i+1],0);
    //     __builtin_prefetch(&b[i+1],0);
    // }
    // for (int i = 0; i < 10000; i++)
    // {
    //     sum+=a[i]+b[i];
    //     sum2+=a[i]+b[i];
    //     sum3+=a[i]+b[i];
    //     sum4+=a[i]+b[i];
    // }
    
    block* c=(block*)malloc(sizeof(block)*NUM);
    block* d=(block*)malloc(sizeof(block)*NUM);
    for (int i = 0; i < 10000; i++){
        __builtin_prefetch(&c[i+4].val,0,0);
        __builtin_prefetch(&c[i+5].val,0,0);
        __builtin_prefetch(&c[i+6].val,0,0);
        __builtin_prefetch(&c[i+7].val,0,0);
        __builtin_prefetch(&c[i+4].val,0,0);
        __builtin_prefetch(&d[i+5].val,0,0);
        __builtin_prefetch(&d[i+6].val,0,0);
        __builtin_prefetch(&d[i+7].val,0,0);
        sum+=c[i].val+d[i].val;
        sum+=c[i+1].val+d[i+1].val;
        sum+=c[i+2].val+d[i+2].val;
        sum+=c[i+3].val+d[i+3].val;

        sum2+=c[i].val+d[i].val;
        sum2+=c[i+1].val+d[i+1].val;
        sum2+=c[i+2].val+d[i+1].val;
        sum2+=c[i+3].val+d[i+1].val;

        sum3+=c[i].val+d[i].val;
        sum3+=c[i+1].val+d[i].val;
        sum3+=c[i+2].val+d[i+2].val;
        sum3+=c[i+3].val+d[i+3].val;

        sum4+=c[i].val+d[i].val;
        sum4+=c[i+1].val+d[i+1].val;
        sum4+=c[i+2].val+d[i+2].val;
        sum4+=c[i+3].val+d[i+3].val;
    }
    gettimeofday(&end,NULL);
    printf("time=%.0fus\n",gettime(&begin,&end));

}