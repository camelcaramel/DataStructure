#include "../ds.h"

typedef struct {
	int key;

} element;

typedef struct treeNode *treePointer;

struct treeNode {
	treePointer leftChild;
	element data;
	short int bf;
	treePointer rightChild;
};

void avlInsert(treePointer *parent, element x, int *unbalanced)
{
	if (!*parent)
	{
		// insert element into null tree
		*unbalanced = TRUE;
		MALLOC(parent, sizeof(treeNode));
		(*parent)->leftChild = (*parent)->rightChild = NULL;
		(*parent)->bf = 0;
		(*parent)->data = x;
	}
	else if (x.key < (*parent)->data.key)
	{
		avlInsert(&(*parent)->leftChild, x, unbalanced);
		if (*unbalanced)
		{
			// left branch has grown higher
			switch ((*parent)->bf)
			{
			case -1:
				(*parent)->bf = 0;
				*unbalanced = FALSE;
				break;
			case 0 : 
				(*parent)->bf = 1;
				break;
			case  1 :
				leftRotation(parent, unbalanced);
				break; 
			default:
				break;
			}
		}
	}
	// ritght same as left 
	else
	{
		*unbalanced  = FALSE;
		puts("The key is already in the tree");
	}
}

void leftRotation(treePointer *parent, int *unbalnced)
{
	treePointer grandChild, child;
	child = (*parent)->leftChild;
	if (child -> bf == 1)
	{
		// LL rotation
		(*parent)->leftChild = child->rightChild;
		child->rightChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else
	{
		// LR rotation

		// 손자 초기화
		grandChild = child->rightChild;
		// RR 시작
		child->rightChild = grandChild->leftChild;
		grandChild->leftChild = child;
		// 여기까지 RR 이제 LL 시작
		(*parent)->leftChild = grandChild->rightChild;
		grandChild->rightChild = *parent;
		// LL 끝

		// set bf value
		switch (grandChild->bf)
		{
		case 1:
			(*parent)->bf = -1;
			child->bf = 0;
			break;
		case 0:
			(*parent)->bf = child->bf = 0;
			break;
		case -1:
			(*parent)->bf = 0;
			child->bf = 1;
			break;
		default:
			break;
		}
		// 결과를 적용
		*parent = grandChild;
	}

	(*parent)->bf = 0;
	*unbalnced = FALSE;
}

int main(void)
{
	char h[] = "hello world";
	
}