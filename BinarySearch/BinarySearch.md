# 이진 탐색 (Binary Search)

- 특징 
  - 정렬된 배열(선형 자료구조)에 사용하는 것을 전제로 한다
  - 찾고자 하는 값과 배열의 중앙 인덱스에 있는 값을 비교하여 값의 일치 여부와 대소 여부를 판단한다

- 장점
  - 검색이 진행될수록 탐색 범위가 절반씩 줄어들게 된다 이는 속도가 빨라짐을 의미한다
  - 데이터의 수가 많아져도 모든 값을 탐색하는 것이 아니기 때문에 탐색 시간이 증가폭이 크지 않다

- 단점
  - 기본적으로 선형 자료구조에서만 사용할 수 있다 (이진탐색트리에서는 Linked List와 이진 탐색을 결합하여 사용한다)
  - 정렬되지 않은 데이터는 정렬을 해줘야 한다

- 시간복잡도는 O(log n)
  - 데이터가 증가할수록 연산 횟수가 로그적으로 증가한다
    - 탐색 범위를 절반으로(2로) 나누고 데이터 탐색 범위가 1개가 될 때까지 연산이 진행된 뒤 마지막 바교연산을 수행하기 때문에 데이터 갯수가 N개일 때 탐색 범위가 1개가 될 때까지의 연산 횟수를 k라고 하면 N*(1/2)^k = 1 이 된다 이를 N과 k에 대해 정리하면 N*2^-k = 1 -> N = 2^k -> log2 N = log2 2^k (로그 바로 뒤의 2는 로그의 밑 이다 이는 이 문서 전체에 적용된다) -> log2 N = k 이 된다 
    - 즉 데이터의 수에 따른 연산 횟수는 log2 N 가 된다 이를 Big O 표기법으로 표시했을 때 O(log n) 이 된다  

- 예시 코드
  - C
  ```
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
  ```
- 출력값
  ```
  타겟 저장 인덱스: 3 
  탐색 실패
  ```
