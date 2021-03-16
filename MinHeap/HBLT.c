/* 
이석호 자료구조 9.2 좌향 트리
451pg 소스코드
20210316(화)
*/

#include <stdlib.h>

#define SWAP(a, b, temp) (temp) = (a); (a) = (b); (b) = (temp);

typedef struct {
	int key;
} element;

struct lefist{
	struct leftist *leftChild;
	element data;
	struct leftist *rightChild;
	int shortest;
};

void minMeld(struct leftsist **a, struct leftist **b)
{
	/*
	두 최소 좌향 트리를 합병한다.
	*/
	if (!*a) *a = *b;
	else if (*b) minUnion(a, b);
	*b = NULL;
}

void minUnion(struct leftist **a, struct leftist **b)
{
	/*
	최소 좌향 트리를 순환적으로 계속 합병한다.
	왼쪽으로 편행성을 지키고
	최소값이 루트가 되는 규칙을 지키면서 합병한다.
	*/

	struct leftist *temp;

	// 루트의 대소를 비교해서 루트를 바꾼다
	if ((*a)->data.key > (*b)->data.key) SWAP(*a, *b, temp);

	// 오른쪽 자식이 없다면 오른쪽 자식을 새로운 트리로 바꾼다
	if (!(*a)->rightChild) (*a)->rightChild = *b;
	// 오른쪽 자식이 있다면 다시 순환적으로 오른쪽 자식과 합병한다.
	else minUnion(&((*a)->rightChild), *b);

	// 왼쪽 자식이 없다면
	if (!(*a)->leftChild)
	{
		// 오르쪽 서브트리를 왼쪽 서브트리로 옮긴다.
		// 이유는 좌향트리여야 하니까
		(*a)->leftChild = (*a)->rightChild;
		(*a)->rightChild = (NULL);
	}
	// 왼쪽 자식은 있는데 왼쪽 서브트리의 높이가 더 낮은 경우에는 왼쪽 서브트리와 오른쪽 서브트리 자리 바꾸기!
	else if ((*a)->leftChild->shortest < (*a)->rightChild->shortest)
		SWAP((*a)->leftChild, (*a)->rightChild, temp);
	// 모든 과정이 끝나고 트리의 shortest 값 수정해주기!
	// 자식이 없으면 1 자식이 있으면 그 자식의 최솟값에 1 더하기!
	// 왜 오른쪽을 기준으로 할까? 위의 과정이 끝나고 나면 왼쪽 트리가 더 길태니 최솟값을 찾으라고 하면
	// 오른쪽을 봐야하니까? 맞다
	(*a)->shortest = (!(*a)->rightChild) ? 1 : (*a)->rightChild->shortest + 1;
}