//#include <stdio.h>
//#pragma warning(disable : 4996)
//
//int main(void)
//{
//  
//  int inputRow = 0;
//  scanf("%d", &inputRow);
//  char ch_center = 'A';
//  for (int row = 0; row < inputRow; row++) {
//    
//    for (int left_head = 0; left_head < inputRow - 1 - row; left_head++) {
//      printf(" ");
//    }
//
//    char ch_left = 'A';
//    for (int left_tail = 0; left_tail < row; left_tail++) {
//      printf("%c", ch_left++);
//    }
//
//    printf("%c", ch_center++);
//
//    char ch_right = 'A' + row - 1;
//    for (int right_head = 0; right_head < row; right_head++) {
//      printf("%c", ch_right--);
//    }
//
//    printf("\n");
//  }
//  
//  return 0;
//}
//
//
//