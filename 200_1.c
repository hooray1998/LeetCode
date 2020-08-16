#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find(int index, int *pre){
    int root = index;
    while(root != pre[root]) root = pre[root];

    //TODO：
    //路径压缩
    int tmp;
    while(index != root){
        tmp = pre[index];
        pre[index] = root;
        index = tmp;
    }

    return root;

}

int un(int a, int b, int *pre){
    int ap = find(a, pre);
    int bp = find(b, pre);
    if (ap != bp){
        pre[ap] = bp;
        return 1;
    }
    return 0;
}


int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid==NULL || gridSize == 0 || gridColSize  == NULL || *gridColSize == 0)
        return 0;
    int size = gridSize * gridColSize[0];
    int *pre = (int *)malloc(sizeof(int) * size);
    int count = 0;

    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            pre[i * gridColSize[i] + j] = i * gridColSize[i] + j;
        }
    }

    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if (grid[i][j] == '1'){
                ++count;

                if(i+1<gridSize && grid[i+1][j] == '1'){
                    count -= un(i*gridColSize[i] + j , (i+1)*gridColSize[i+1] + j, pre);
                }
                if(i-1>=0 && grid[i-1][j] == '1'){
                    count -= un(i*gridColSize[i] + j , (i-1)*gridColSize[i-1] + j, pre);
                }
                if(j+1<gridColSize[i] && grid[i][j+1] == '1'){
                    count -= un(i*gridColSize[i] + j , (i)*gridColSize[i] + j + 1, pre);
                }
                if(j-1>=0 && grid[i][j-1] == '1'){
                    count -= un(i*gridColSize[i] + j , (i)*gridColSize[i] + j - 1, pre);
                }
            }
        }
    }
    return count;

}

int main(){
    char *a[6] = {
        "11000",
        "11000",
        "00100",
        "00011"
    };
    int cs[] = {5, 5, 5, 5};
    printf("count:%d\n", numIslands((char **)a, 4, cs));


    return 0;
}

