#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int trap(int* height, int heightSize){
    int *s = (int *)malloc(heightSize * sizeof(int));
    int size = 0;
    int sum = 0;
    int diff;
    int min;
    //单调栈里面存储的是索引， 不是tmd数值
    //每次pop的时候看清楚怎么处理， 别急的跟兔子似的，
    //注意边界

    for(int i=0;i<heightSize;i++){

        while(size > 0 && height[s[size-1]] <= height[i]){
            --size;
            if(size >0 ){
                min = (height[s[size-1]] < height[i])? height[s[size-1]] : height[i];
                sum += (min - height[s[size]]) * (i - s[size-1] -1);
                //printf("add %d: in [%d]:%d\n", (min - height[s[size]]) * (i - s[size-1] -1), i, height[i]);
            }
        }
        s[size++] = i;
        //for(int j=0;j<size;j++){
            //printf("%d ", height[s[j]]);
        //}
        //printf("\n");
    }

    return sum;
}

int trap2(int* height, int heightSize){
    int maxi = 0;
    int max = 0;

    int sum = 0;
    int left = 0;
    int right = 0;
    int cur = 0;
    if(heightSize<=2){
        return 0;
    }

    for(int i=0;i<heightSize;i++){
        if ( height[i] > max){
            max = height[i];
            maxi = i;
        }
        sum += height[i];
    }
    for(int i=0;i<maxi;i++){
        if ( height[i] > cur){
            cur=height[i];
        }
        left += cur;
    }
    cur = 0;
    for(int i=heightSize-1;i>maxi;i--){
        if ( height[i] > cur){
            cur=height[i];
        }
        right += cur;
    }
    return left + right + max - sum;
}

int main(){

   // int h[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int h[] = {4,3,2,1,0,1,2,4};
    printf("%d\n", trap(h, 8));
    printf("%d\n", trap2(h, 8));
    //srand(time(NULL));
    //printf("%d\n", rand()%1000);

    return 0;
}
