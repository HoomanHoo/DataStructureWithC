#include <stdio.h>

int LinearSearch(int ar[], int length, int target)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (ar[i] == target) // 최악의 경우(target이 배열 맨 마지막 인덱스에 존재할 때) 데이터-ar[]의 요소 갯수가 늘어나면 연산량도 늘어난다 -> 데이터 n개시 연산 n번 수행
        {
            return i; // target 과 같은 배열의 인덱스값 반환
        }
        // else{
        //     return -1;
        // }
    }
    return -1; // target 과 같은 값을 배열 내에서 찾지 못했을 때 -1을 반환한다
}

int main(void)
{
    int arr[] = {3, 5, 2, 4, 9};
    int index;
    int index2;

    index = LinearSearch(arr, sizeof(arr) / sizeof(int), 4); // sizeof(피연산자)는 피연산자의 크기를 바이트 단위로 반환한다
    if (index == -1)
    {
        printf("탐색 실패 \n");
    }
    else
    {
        printf("타겟이 저장된 인덱스: %d \n", index);
    }

    index2 = LinearSearch(arr, sizeof(arr) / sizeof(int), 7);
    if (index2 == -1)
    {
        printf("탐색 실패 \n");
    }
    else
    {
        printf("타겟이 저장된 인덱스: %d \n", index2);
    }

    return 0; // 에러 없이 함수가 종료되었음을 OS에 알려주기 위하여 사용함
}