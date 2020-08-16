#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
不能设置长度为3001， 因为如果3001个全部填充了数字， 则两个指针和初始化时一样， 长度3001会变成0
所以要设置数组大小为3002，这样end永远不会追上front
*/
typedef struct {
    int queue[3002];
    int front;
    int end;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *ret = (RecentCounter *)malloc(sizeof(RecentCounter));
    ret->front = 0;
    ret->end = 0;
    return ret;
}

int recentCounterPing(RecentCounter* obj, int t) {
    while (obj->front != obj->end && (obj->queue[obj->front] + 3000) < t) {
        obj->front = (obj->front+1)%3002;
    }
    obj->queue[obj->end] = t;
    obj->end = (obj->end+1)%3002;
    return (obj->end - obj->front + 3002 ) % 3002;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/


int main(){

    RecentCounter* obj = recentCounterCreate();
    printf("%d\n", recentCounterPing(obj, 1));
    printf("%d\n", recentCounterPing(obj, 100));
    printf("%d\n", recentCounterPing(obj, 3001));
    printf("%d\n", recentCounterPing(obj, 3002));
    recentCounterFree(obj);

    return 0;
}