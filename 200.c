#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void dfs(char** grid, int i, int j, int row, int col, char *visited){
    int index;
    index = i*col + j;
    visited[index] = 1;

    if(i+1<row && grid[i+1][j] == '1' && ! visited[(i+1)*col + j]){
        dfs(grid, i+1, j, row, col, visited);
    }
    if(j+1<col && grid[i][j+1] == '1' && ! visited[(i)*col + j + 1]){
        dfs(grid, i, j+1, row, col, visited);
    }
    if(i-1>=0 && grid[i-1][j] == '1' && ! visited[(i-1)*col + j]){
        dfs(grid, i-1, j, row, col, visited);
    }
    if(j-1>=0 && grid[i][j-1] == '1' && ! visited[(i)*col + j - 1]){
        dfs(grid, i, j-1, row, col, visited);
    }

}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid==NULL || gridSize == 0 || gridColSize  == NULL || *gridColSize == 0)
        return 0;
    int size = gridSize * gridColSize[0];
    char *visited = (char *)malloc(sizeof(char) * size);
    memset(visited, 0, size);
    int count = 0;

    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if (!visited[i*gridColSize[i] + j] && grid[i][j] == '1'){
                ++count;
                dfs(grid, i, j, gridSize, gridColSize[i], visited);
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

