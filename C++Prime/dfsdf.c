#include <stdio.h>
int main(void)
{
  int min, max;
  int sum = 0;

  printf("������ ���Ѱ� ������ �Է��Ͻÿ�: ");
  scanf_s("%d%d", &min, &max);
  while (min != max || min < max) {
    int min_sq = min * min;
    int max_sq = max * max;
    for (int i = min; i < max + 1; i++) {
      int i_sq = i * i;
      sum = sum + i_sq;
    }
    printf("%d���� %d����, �������� ���� %d\n", min_sq, max_sq, sum);
  }
  printf("����!\n");
  return 0;
}