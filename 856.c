//856. 括号的分数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int handNext(char *s, int *start){

    int sum = 0;
    while( s[*start] != '\0'){
        if ( s[*start] == '('){
            *start += 1;
            sum += handNext(s, start);
        }
        else {
            *start += 1;
            sum *= 2;
            return (sum == 0)? 1: sum;
        }
    }

    return sum;
}

int answer(char *s){
    int len = strlen(s);
    int *stack = (int *)malloc(sizeof(int)*len);
    int ss=0;

    int sum;
    for(int i=0;i<len;i++){
        if(s[i] == '('){
            stack[ss++] = 0;
        }else{
            if(stack[ss-1] == 0){
                stack[ss-1] = 1;
            }else{
                sum = 0;
                while(stack[ss-1]!=0){
                    sum += stack[ss-1];
                    --ss;
                }
                stack[ss-1] = sum * 2;
            }
        }
    }
    sum = 0;
    for(int i=0;i<ss;i++){
        sum += stack[i];
    }
    return sum;
}


int scoreOfParentheses(char * S){

    int start = 0;
    if((strlen(S)/2)%2==0){
        return handNext(S, &start);
    }
    else{
        return answer(S);
    }
}

int main(){
    printf("%d", scoreOfParentheses("((()))()"));

    return 0;
}
