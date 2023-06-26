#include <stdio.h>
int main(void)
{
  int min, max;
  int sum = 0;

  printf("정수로 하한과 상한을 입력하시오: ");
  scanf_s("%d%d", &min, &max);
  while (min != max || min < max) {
    int min_sq = min * min;
    int max_sq = max * max;
    for (int i = min; i < max + 1; i++) {
      int i_sq = i * i;
      sum = sum + i_sq;
    }
    printf("%d부터 %d까지, 제곱들의 합은 %d\n", min_sq, max_sq, sum);
  }
  printf("종료!\n");
  return 0;
}