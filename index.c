#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * 判断是否为完全平方数
 * @return {int res} 1: 是, 0: 否
 */
int targetNum(int num)
{
  double res = pow(num, 0.5);
  return res - (int)res == 0;
}
/**
 * @return {int steps} 返回变成完数所需操作次数
 */
int searchNum(int num)
{
  // stepA前找, stepB后找
  int stepA = 0, stepB = 0, numBak = num;
  if (!num)
    return 2;
  while (1)
  {
    stepA++;
    if (targetNum(++num))
      break;
  }
  while (1)
  {
    stepB++;
    if (--numBak < 0)
      break;
    if (targetNum(numBak))
      break;
  }
  return stepA < stepB ? stepA : stepB;
}
/**
 * 冒泡排序
 */
void bubbleSort(int *arr, int len)
{
  for (int i = 0; i < len - 1; i++)
  {
    int flag = 1;
    for (int j = 0; j < len - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        flag = 0;
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
    if (flag) return;
  }
}
int main()
{
  int n = 2, tn = 0, totalStep = 0;
  scanf("%d", &n);
  if (n < 2 || n % 2) return 1;
  int *arr = (int *)malloc(4 * n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
    if (targetNum(arr[i]) && arr[i] != 0) tn++;
  }
  // 输如的数据原本就满足条件, 直接输出结果
  if (tn == n / 2)
  {
    printf("TOTAL STEPS: %d\n", 0);
    return 1;
  }
  // 将每个数替换成其变成完数所需最小步骤
  for (int i = 0; i < n; i++)
    arr[i] = targetNum(arr[i]) && arr[i] != 0 ? 0 : searchNum(arr[i]);
  // 冒泡排序
  bubbleSort(arr, n);
  // 计算总操作次数
  if (tn > n / 2) {
    totalStep = tn - n / 2;
  } else {
    for (int i = 0; i < n / 2; i++)
      totalStep += arr[i];
  }
  
  printf("TOTAL STEPS: %d\n", totalStep);
  return 0;
}