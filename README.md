# Data_structure

⚙️ 프로그램 개요
  - 자료구조들의 특징과 정렬 알고리즘을 공부하고 이를 C언어로 구현하였습니다.
  - openCV를 사용하여 이미지를 회전시키는 코드를 구현하였습니다.

✏️ Skils
  - C
  - C++
  - OpenCV

목차  
1. [Linked List](#linked-list)
2. [Stack](#stack)
3. [Queue](#queue)
4. [Bubble Sort](#buble-sort)
5. [Merge Sort](#merge-sort)
6. [Selection Sort](#selection-sort)
7. [MatMul](#matmul)
8. [RotateImage](#rotate-image)

# Linked List
- 연결리스트의 구조를 이해하고 연결리스트의 CRUD를 Big-O가 O(1)을 만족할 수 있도록 구현하였습니다.
  ![KakaoTalk_Photo_2023-10-25-16-10-17 001](https://github.com/Yeji-Jang1210/Data-structure/assets/62092491/51d89c94-47e7-4f77-bdbc-d293e64f29b7)

# Stack
- Stack의 구조를 이해하고 연결리스트로 구현하였습니다.
- Stack은 후입선출로 항목을 넣는 Push와 항목을 꺼내는 Pop을 실행하고 Stack의 CRUD를 구현하였습니다.
  
# Queue
- Queue의 자료구조를 이해하고 Queue 자료구조 형태를 연결리스트로 구현하였습니다.
- Queue의 rear에서는 항목을 넣는 EnQueue작업을, front에서는 항목을 삭제하는 DeQueue작업을 실행하도록 구현하였습니다.

# Bubble Sort
- 버블정렬의 알고리즘을 이해하고 Int형 배열을 정렬하는데 걸리는 시간을 재도록 구현하였습니다.
  버블정렬이란?
    원소의 이동이 거품이 수면위로 올라오는 듯한 모습을 보이기 때문에 지어진 이름이며, 두 인접한 원소를 비교하여 정렬하는 방법입니다.  
    보통의 경우 버블정렬의 시간 복잡도는 O(n^2)이지만, 비교가 끝났을 경우 for문을 탈출하면 O(n)까지 줄일 수 있습니다.
  ![KakaoTalk_Photo_2023-10-25-16-09-59 001](https://github.com/Yeji-Jang1210/Data-structure/assets/62092491/b0eb70dc-d255-485b-b7a8-0d8d5825f5b8)


# Merge Sort
- 합병정렬의 알고리즘을 이해하고 Int형 배열을 정렬하는 기능을 구현하였습니다.
- 재귀함수를 사용해 원소가 나눠질 수 없을 때까지 나눈 후 함수가 실행이 완료되고 돌아오면서 원소를 비교하고 병합하는 원리입니다.
![mergesort_image](https://github.com/Yeji-Jang1210/Data-structure/assets/62092491/518db030-1fc3-4346-b371-f96fb7bb9859)
  

# Selection Sort
- 선택정렬의 알고리즘을 이해하고 Int형 배열을 정렬하는 기능을 구현하였습니다.
- 선택정렬은 배열에서 최소값을 찾아 최소값이 있던 자리와 맨 앞의 배열의 자리를 바꿔주면서 정리하는 배열입니다.
- 배열 전체를 돌면서 비교하기 때문에 시간 복잡도가 O(n^2) 입니다.
  ![KakaoTalk_Photo_2023-10-25-16-09-59 002](https://github.com/Yeji-Jang1210/Data-structure/assets/62092491/cfdf4e75-3072-4c86-8963-32c93eb62564)

  
# MatMul  
- 행렬의 구조를 이해하고, 텍스트 파일을 받아 행렬의 곱을 처리하는 소스를 구현하였습니다.
   1. 2차원 동적배열을 할당받아 구현
   2. 1차원 동적배열을 할당받아 구현
   3. 구조체를 사용해 1차원 배열 할당받아 구현
   4. main 함수 간소화 및 함수추가(최종)
- 텍스트 파일의 형식은 밑의 형식으로 이루어져있습니다.
  (행, 열)
  위 행열에 맞는 값
![KakaoTalk_Photo_2023-10-25-16-10-18 003](https://github.com/Yeji-Jang1210/Data-structure/assets/62092491/b8821e53-f5bd-4cfc-b482-2d21638ba266)

# Rotate Image
- 행렬의 구조를 이해하고 openCV를 통해 이미지를 회전하는 기능을 구현하였습니다.
- 행렬의 회전원리는 회전행렬을 참고하여 구현하였습니다.
- 회전시킬 이미지를 띄울 Mat img를 하나 만든 후 [i , j]를 회전시켜 그에 해당하는 값을 원본에서 가져오는데, 이렇게 할경우 겹치는 값이 생기기 때문에 최대한 근사한 값을 찾아 대입해줘야합니다.(보간법을 사용하였습니다.)
  
![rotateImage](https://github.com/Yeji-Jang1210/Data-structure/assets/62092491/8cec0445-25e3-4885-a15a-19f9971e2530)

