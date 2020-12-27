#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void TravelToString(char* s1, char* s2){
    char c;
    int flag = 1, i = 0;
    int max = -1;
    while(i != max){
        scanf("%c", &c);
        if(c == ' ') {
            flag = 0;
            s1[i] = '\0';
            max = i;
            i = 0;
            continue;
        }
        if(flag){
            s1[i++] = c;
        }else{
            s2[i++] = c;
        }
    }
    s2[i] = '\0';
}
void PrintPreorder(char* s1, int len1, char* s2, int len2){
    if(len1 == 0) return;
    char root = s2[len2 - 1];
    printf("%c", root);
    int index = -1;
    while(s1[++index] != root);
    PrintPreorder(s1, index, s2, index);
    PrintPreorder(s1 + index + 1, len1 - index - 1, s2 + index, len1 - index - 1);
}
int main(){
    char s1[20], s2[20];
    int len1, len2;
    TravelToString(s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    PrintPreorder(s1, len1, s2, len2);
    
    return 0;
}
