#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int arr[10];
int box[10];
int cmp(const void*a,const void*b){
    return (*(int *)a-*(int*)b);
}
int main(){
    for(int i=0;i<8;i++){
        scanf("%d",&arr[i]);
        box[i]=arr[i];
    }
    qsort(box,8,4,cmp);
    int sum=0;
    for(int i=7;i>=3;i--){
        sum+=box[i];
    }
    printf("%d\n",sum);
    for(int i=0;i<8;i++){
        for(int j=0;j<5;j++){
            if(box[8-1-j]==arr[i]){
                
                printf("%d ",i+1);
            }
        }
    }
    return 0;
}
