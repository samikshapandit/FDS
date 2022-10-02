#include<stdio.h>
void prime(int start,int end);
int main()
{
  int start,end;
  scanf("%d%d",&start,&end);
  prime(start,end);
}
void prime(int start,int end)
{ 
  int i,j;
  int flag=0;
  for(int i=start;i<=end;i++)
    {
      for(j=2;j<i;j++)
        {
          if(i%j==0)
            flag++ ;
        }
      if(flag==0)
        printf("%d  ",i);
      else
        flag=0;
    }
}