// 2019.09.24

#include <stdio.h>

int main()
{
  int n, top[500000] = {}, log[500000] = {};
  scanf("%d",&n);

  for (int i = 0 ; i < n ; i++)
  {
    scanf("%d",&top[i]);
  }

  log[0] = -1;
  printf("%d",log[0]+1);

  for (int i = 1 ; i < n ; i++)
  {
    int now = i-1;
    while (true)
    {
      //printf("%d %d %d %d %d\n",i,now,top[now],top[i],log[now]);
      if (now == -1) {log[i] = -1; //printf(" %2d : %d\n",i,log[i]);
        break;}
      if (top[now] >= top[i]) {log[i] = now; //printf(" %2d : %d\n",i,log[i]);
        break;}
      else {now = log[now];}
    }

    printf(" %d",log[i]+1);
  }
}
