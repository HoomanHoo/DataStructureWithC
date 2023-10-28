#include <stdio.h>

int BinarySearch(int ar[], int length, int target)
{
    int first = 0;
    int last = length - 1;
    int middle;

    while (first <= last)
    {
        middle = (first + last) / 2; // 중앙 인덱스 값을 구한다

        if (target == ar[middle]) // 우선 중앙 인덱스에 찾는 값이 있는지 판단한다
        {
            return middle;
        }
        else
        {
            if (target < ar[middle]) // 찾는 값이 중앙 인덱스에 있는 값보다 작을 경우
            {
                last = middle - 1; // 탐색 범위의 끝을 중앙 인덱스보다 하나 작게 해서 다시 중앙 인덱스를 구하고 값을 판단한다
            }
            else // 찾는 값이 중앙 인덱스에 있는 값보다 클 경우
            {
                first = middle + 1; // 탐색 범위의 시작 값을 중앙 인덱스보다 하나 큰 값으로 해서 다시 중앙 인덱스를 구하고 값을 판단한다
            }
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int index;
    int index2;

    index = BinarySearch(arr, sizeof(arr) / sizeof(int), 7);
    if (index == -1)
    {
        printf("탐색 실패\n");
    }
    else
    {
        printf("타겟 저장 인덱스: %d \n", index);
    }

    index2 = BinarySearch(arr, sizeof(arr) / sizeof(int), 4);
    if (index2 == -1)
    {
        printf("탐색 실패\n");
    }
    else
    {
        printf("타겟 저장 인덱스: %d \n", index2);
    }
    return 0;
}