#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int failure[101];
void fail(char *pat)
{
 int i,j;
 int n=strlen(pat);
 failure[0]=-1;
 for(j=1;j<n;j++)
 {
  i=failure[j-1];
  while((pat[j]!=pat[i+1] && i>=0))
  i=failure[i];

 if(pat[j]==pat[i+1])
   failure[j]=i+1;
 else
   failure[j]=-1;
 }
}

int pmatch(char *str,char *pat)
{
 int i=0,j=0;
 int lens=strlen(str);
 int lenp=strlen(pat);
 while(i<lens && j<lenp)
 {
  if(str[i]==pat[j])
  {
   i++;
   j++;
  }
  else if (j==0)
   i++;
  else
   j=failure[j-1]+1;
 }
return ((j==lenp)?(i-lenp):-1);
}

int main(){
 char st[101],pt[101];
 printf("Enter String:-  ");
 scanf("%s",st);
 printf("enter pattern to check:- ");
 scanf("%s",pt);
 fail(pt);

 int r=pmatch(st,pt);
 if(r==-1)
  printf("substring not found\n");
 else
  printf("Starting index of pattern is - %d\n",r);
}
