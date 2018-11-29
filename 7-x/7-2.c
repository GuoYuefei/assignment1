#include <stdio.h>

int main() {
  int num = 0;
  int temp;
  scanf("%d",&num);
  int min;
  for(int i = 0; i < num; i++) {
    scanf("%d ", &temp);
    if(i == 0) min = temp;
    min = min < temp ? min : temp;
  }
  printf("min = %d", min);
  
  
  return 0;
}
