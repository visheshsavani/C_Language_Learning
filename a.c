#include <stdio.h>
#include <string.h>
int lcs(char a[],char b[],int m,int n){
    int l[m+1][n+1];
    for (int i = 0; i <=m; i++)
    {
        for (int j = 0; j <=n; j++)
        {
            if(i==0 || j==0){
                l[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                l[i][j] = l[i-1][j-1] +1;
            }
            else{
                l[i][j] = (l[i-1][j]>l[i][j-1])?l[i-1][j]:l[i][j-1];
            }
        }
        
    }
    return l[m][n];
}
int main(){
    char s1[]= "abc";
    char s2[]= "bc";
    int m = strlen(s1);
    int n = strlen(s1);
    printf("length of lcs is %d\n",lcs(s1,s2,m,n));
}