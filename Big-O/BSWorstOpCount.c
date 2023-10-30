#include <stdio.h>

int LinearSearch(int ar[], int length, int target) // 선형 탐색 알고리즘
{
    int i;
    int operateCount = 0;
    for (i = 0; i < length; i++)
    {
        if (ar[i] == target) // 최악의 경우(target이 배열 맨 마지막 인덱스에 존재할 때) 데이터-ar[]의 요소 갯수가 늘어나면 연산량도 늘어난다 -> 데이터 n개시 연산 n번 수행
        {
            return i; // target 과 같은 배열의 인덱스값 반환
        }
        // else{
        //     return -1;
        // }
        operateCount += 1;
    }
    printf("선형 탐색 알고리즘의 비교 연산 횟수: %d \n", operateCount);
    return -1; // target 과 같은 값을 배열 내에서 찾지 못했을 때 -1을 반환한다
}

int BSearch(int ar[], int length, int target) // 이진 탐색 알고리즘
{
    int first = 0;
    int last = length - 1;
    int middle;
    int operationCount = 0; // 비교연산 횟수 기록 변수

    while (first <= last)
    {
        middle = (first + last) / 2;

        if (target == ar[middle])
        {
            return middle;
        }
        else
        {
            if (target < ar[middle])
            {
                last = middle - 1; // 찾고자 하는 값이 중간 값보다 작으면 중간값 바로 앞 인덱스를 탐색범위 마지막으로 변경한다
            }
            else
            {
                first = middle + 1; // 찾고자 하는 값이 중간 값보다 크면 중간값 바로 뒤 인덱스를 탐색범위 시작으로 변경한다
            }
        }
        operationCount += 1; // 비교연산 횟수 1 추가
    }
    printf("이진 탐색 알고리즘의 비교 연산 횟수: %d \n", operationCount); // 탐색 실패시 연산 횟수 출력
    return -1;                                                            // 탐색 실패의 의미로 임의의 값 -1을 리턴한다
}

int main(void)
{
    int arr1[500] = {
        0,
    }; // 모든 요소를 0으로 초기화 한다
    int arr2[5000] = {
        0,
    };
    int arr3[50000] = {
        0,
    };
    int index;

    int linearIndex;

    // 배열 arr1을 대상으로 저장되지 않은 정수 '1'을 탐색하도록 함

    // int sizeOfArray = sizeof(arr1);
    // int sizeOfInt = sizeof(int);
    // int size = sizeOfArray / sizeOfInt;

    // printf("어레이 사이즈: %d \n", sizeOfArray);
    // printf("인트 사이즈: %d \n", sizeOfInt);
    // printf("어레이 나누기 인트 사이즈: %d \n", size);

    // 어레이 사이즈 : 2000 인트 사이즈 : 4 어레이 나누기 인트 사이즈 : 500

    linearIndex = LinearSearch(arr1, sizeof(arr1) / sizeof(int), 1);

    if (linearIndex == -1)
    {
        printf("탐색 실패 \n\n");
    }
    else
    {
        printf("타겟 저장 인덱스: %d \n", linearIndex);
    }

    index = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);

    if (index == -1)
    {
        printf("탐색 실패 \n\n");
    }
    else
    {
        printf("타겟 저장 인덱스: %d \n", index);
    }

    linearIndex = LinearSearch(arr2, sizeof(arr2) / sizeof(int), 2);

    if (linearIndex == -1)
    {
        printf("탐색 실패 \n\n");
    }
    else
    {
        printf("타겟 저장 인덱스: %d \n", linearIndex);
    }

    // 배열 arr2을 대상으로 저장되지 않은 정수 '2'을 탐색하도록 함
    // printf("arr2의 사이즈: %d \n", sizeof(arr2) / sizeof(int)); // arr2의 사이즈: 5000

    index = BSearch(arr2, sizeof(arr2) / sizeof(int), 2);

    if (index == -1)
    {
        printf("탐색 실패 \n\n");
    }
    else
    {
        printf("타겟 저장 인덱스: %d \n", index);
    }

    linearIndex = LinearSearch(arr3, sizeof(arr3) / sizeof(int), 3);

    if (linearIndex == -1)
    {
        printf("탐색 실패 \n\n");
    }
    else
    {
        printf("타겟 저장 인덱스: %d \n", linearIndex);
    }

    // 배열 arr3을 대상으로 저장되지 않은 정수 '3'을 탐색하도록 함
    // printf("arr3의 사이즈: %d \n", sizeof(arr3) / sizeof(int)); // arr3의 사이즈: 50000

    index = BSearch(arr3, sizeof(arr3) / sizeof(int), 3);

    if (index == -1)
    {
        printf("탐색 실패 \n\n");
    }
    else
    {
        printf("타겟 저장 인덱스: %d \n", index);
    }
}

// 출력 값
// 선형 탐색 알고리즘의 비교 연산 횟수: 500
// 탐색 실패

// 이진 탐색 알고리즘의 비교 연산 횟수: 9
// 탐색 실패

// 선형 탐색 알고리즘의 비교 연산 횟수: 5000
// 탐색 실패

// 이진 탐색 알고리즘의 비교 연산 횟수: 13
// 탐색 실패

// 선형 탐색 알고리즘의 비교 연산 횟수: 50000
// 탐색 실패

// 이진 탐색 알고리즘의 비교 연산 횟수: 16
// 탐색 실패

// 함수의 변수를 초기화 해주지 않으면 여러 곳에서 해당 함수를 호출할 경우 변수 값은 이전에 사용한 값이 남아서 계속 사용된다