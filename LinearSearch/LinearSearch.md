# 순차 검색 알고리즘 (Sequential Search)

- 특징 
  - 선형 검색 알고리즘이라고도 한다 (Linear Search)
  - 선형(Linear)으로 자료를 탐색하는 방식
  - 자료구조를 순회할 수 있으면 사용할 수 있다
  - 정렬되지 않은 배열에서 사용하는 경우가 많음
  
- 장점
  - 구현이 쉽다 ( 기본적으로 배열을 순회할 반복문만 있으면 된다)

- 단점
  - 찾고자 하는 데이터가 배열의 뒤쪽에 있을 경우, 모든 데이터를 탐색하기 때문에 시간이 오래 걸린다 
  - 찾고자 하는 데이터가 배열의 뒤쪽에 있을 경우, 배열의 길이가 길어질수록 탐색에 시간이 오래 걸린다

- 시간복잡도는 O(n)
  - 최악의 경우 배열안의 모든 데이터를 비교연산 해야하기 때문에 n개의 데이터가 있으면 n번의 비교 연산을 수행하기 때문이다

- 예시 코드 
  - C
  ```
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
  ```

- 출력값 
  
  ```
  타겟이 저장된 인덱스: 3 
  탐색 실패
  ```