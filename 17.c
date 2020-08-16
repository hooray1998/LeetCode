#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//16:10 start
char ** letterCombinations(char * digits, int* returnSize){
    // 1. 把所有内存全部申请好
    // 2. 一个字母一个字母的处理
    // 3. 先把第一个字母填写在所有的数组上，然后再处理第二个字母。
    //
    // 如果有更快的方法应该是先输出一个结果，再输出第二个结果
    int len = strlen(digits);

    if(len == 0){
        *returnSize = 0;
        return NULL;
    }
    int retSize = 1;
    for(int i=0; i<len; i++){
        if (digits[i] == '9' || digits[i] == '7') retSize *= 4;
        else retSize *= 3;
    }
    *returnSize = retSize;

    char **ret =  (char **)malloc(sizeof(char *) * retSize);
    for(int i=0; i<retSize; i++){
        ret[i] = (char *)malloc(sizeof(char) * (len+1));
        ret[i][len] = '\0';
    }

    int repeat = retSize;
    int group = 1;
    int line; // 当前是第几个数组
    char cur, start, end;
    for(int i=0; i<len; i++){
        // 遍历第几个位置 = i
        // 填充的位置为 [line][i]

        cur = digits[i];
        line = 0;

        if (cur < '7'){
            start = (cur - '2')*3 + 'a';
            end = (cur - '2')*3 + 'd';
        } else if (cur == '7') {
            start = 'p';
            end = 't';
        } else if (cur == '8') {
            start = 't';
            end = 'w';
        } else {
            start = 'w';
            end = 'z' + 1;
        }

        if (cur == '9' || cur == '7'){
            repeat /= 4;
        } else {
            repeat /= 3;
        }

        for(int g=0; g<group; g++){
            for(char c=start; c<end; c++){
                for(int count=0; count<repeat; count++){
                    ret[line][i] = c;
                    ++line;
                }
            }
        }


        if (cur == '9' || cur == '7'){
            group *= 4;
        } else {
            group *= 3;
        }

    }

    return ret;
}

int main(){
    char d[] = "7";
    int retSize;
    char **ret;
    puts("hello");
    ret = letterCombinations(d, &retSize);
    for(int i=0; i<retSize; i++){
        printf("%s\n", ret[i]);
    }

    return 0;
}
