#include<stdio.h>

/* 
 * 616  给字符串添加加粗标签（会员题目）
 * KMP算法
 *
 *
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Next(char*T,int *next){
    next[1]=0;
    int i=1;
    int j=0;
    int lenT = strlen(T);
    while (i<lenT) {
        if (j==0||T[i-1]==T[j-1]) {
            i++;
            j++;
            if (T[i-1]!=T[j-1]) {
               next[i]=j;
            }
            else{
                next[i]=next[j];
            }
        }else{
            j=next[j];
        }
    }
}
int KMP(char * S,char * T, int start){
    int lenT = strlen(T);
    int lenS = strlen(S);
    if (lenT == 0 || lenS == 0){
        return -1;
    }
    int *next = (int *)malloc(sizeof(int) * (lenT+1));
    Next(T,next);//根据模式串T,初始化next数组
    int i=1 + start;
    int j=1;
    while (i<=lenS&&j<=lenT) {
        //j==0:代表模式串的第一个字符就和当前测试的字符不相等；S[i-1]==T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }
        else{
            j=next[j];//如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
        }
    }
    if (j>lenT) {//如果条件为真，说明匹配成功
        return i-lenT-1;
    }
    return -1;
}

char *addBoldTag(char *s, char **dict, int dictSize){
    if ( s == NULL || dict == NULL || dictSize == 0){
        return NULL;
    }
    int lens = strlen(s);
    int *b = (int *)malloc(sizeof(int) * (lens+1));
    int offset;
    //memset(b, 0, sizeof(int)*(lens+1));
    for(int i=0;i<lens+1;i++){
        b[i] = 0;
    }
    for(int i=0;i<dictSize;i++){
        offset = 0;
        while((offset = KMP(s, dict[i], offset))!=-1){
            printf("'%s' in '%s'  at %d\n", dict[i], s, offset);
            //getchar();
            b[offset] += 1;
            b[offset+strlen(dict[i])] -= 1;
            offset += 1;
        }
    }
    for(int i=0;i<lens+1;i++)
        printf("%c %d\n", s[i], b[i]);
    int left = -1;
    int right = -1;
    int count = 0;
    for(int i=0;i<lens+1;i++){
        //printf("%c %d\n", s[i], b[i]);
        if (b[i] > 0){
            if (left == -1 ){
                count += 7;
                left = i;
                right = -1;
            } else {
                b[i] = 0;
            }
        } else if (b[i] < 0){
            if (right == -1){
                right = i;
                left = -1;
            } else {
                b[right] = 0;
                right = i;
            }
        }

    }
    char *res = (char *)malloc(sizeof(char) * (lens+count+1));
    int j = 0;
    for(int i=0;i<lens+1;i++) {
        if (b[i] == 0){
            res[j] = s[i];
            ++j;
        } else if (b[i] > 0){
            strcat(res+j, "<b>");
            res[j] = '<';
            res[j+1] = 'b';
            res[j+2] = '>';
            res[j+3] = s[i];
            j += 4;
        }else{
            res[j] = '<';
            res[j+1] = '\\';
            res[j+2] = 'b';
            res[j+3] = '>';
            res[j+4] = s[i];
            j += 5;
        }
    }
    res[j] = '\0';
    return res;
}
int main() {
    //char *s = "";
    //int i=KMP("ababcabcacbab",s);
    //printf("%d",i);
    char *p[] = {"abc", "abc", "a", "bcd", "d", "eda"};
    char *s = "bcabcdefccedaf";
    printf("res: '%s'\n", addBoldTag(s, p, 6));

    return 0;
}
