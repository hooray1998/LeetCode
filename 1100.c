#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int numKLenSubstrNoRepeats(char *S, int K){
    int lenS = strlen(S);
    if ( K > lenS ){
        return 0;
    }
    char e[26];
    memset(e, 0, 26);

    int left = 0;
    int right = 0;
    int count = 0;

    while(right < lenS){
        if( e[S[right] - 'a'] == 0) {
            e[S[right] - 'a'] = 1;
            ++right;
            if (right == left + K){
                ++count;

                e[S[left] - 'a'] = 0;
                ++left;
            }
        } else {
            memset(e, 0, 26);
            left = right;
        }
        //printf("%d,%d\n", left, right);
        //getchar();
    }

    return count;

}


int main(){

    printf("%d \n ", numKLenSubstrNoRepeats("havefunonleetcode", 8));



    return 0;
}
