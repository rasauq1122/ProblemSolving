// 2019.08.29

#include <stdio.h>
#define and &&

int main() 
{
  int man, gate;
  scanf("%d %d",&man,&gate);

  int moon[100] = {}, foot[100] = {};
  for (int i = 0 ; i < man ; i++)
  {
    scanf("%d",&moon[i]);
  }

  for (int i = 0 ; i < gate ; i++)
  {
    int past = 0;
    for (int j = 0 ; j < man ; j++)
    {
      if (foot[moon[j]-1] == 0 and (past < moon[j]))
      {
      	//printf("%d %d\n",i,moon[j]);
        past = moon[j];
        foot[moon[j]-1] = 1;
      }
    }
  }

  for (int i = 0 ; i < man ; i++)
  {
    if (foot[i]==0) {printf("NO"); return 0;} 
  }
  printf("YES");
}