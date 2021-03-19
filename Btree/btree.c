#include <stdio.h>

#define BTREE_ORDER 5

typedef struct BTreeNodeDataType
{
	int key;
	char value;
} BTreeNodeData;

typedef struct BTreeNodeType{
	int count;
	BTreeNodeData data[BTREE_ORDER];
	struct BTreeNodeType *children[BTREE_ORDER + 1];
} BTreeNode;

typedef struct BTreeType
{
	BTreeNode *pRootNode;
} BTree;

BTreeNodeData *searchBT(BTree *pBTree, int key)
{
	/*비트리를 탐색하면서 키가 같은 데이터를 찾아서 데이터의 포인터를 반환하는 함수*/
	BTreeNodeData *pReturn = NULL;
	BTreeNode *pCurrentNode = NULL;
	int i = 0;

	if (pBTree != NULL)
	{
		pCurrentNode = pBTree->pRootNode;
		while (pCurrentNode != NULL)
		{
			// 마지막 노드 가기전까지 게속해서 반복...
			for (i = 0; i < pCurrentNode->count; i++)
			{
				// 한 노드안에 저장된 모든 데이터들과 키값을 비교
				int currentKey = pCurrentNode->data[i].key;
				if (key == currentKey)
				{
					// 키값과 일치하는 데이터를 찾았고 데이터 포인터를 담아서 리턴
					pReturn = &pCurrentNode->data[i];
					return pReturn;
				}
				else if (key < currentKey)
				{
					// 키 값과 동일한 데이터가 존재하지 않음
					break;
				}
			}
			pCurrentNode = pCurrentNode->children[i];
		}
	}
	return pReturn;
}

int addDataBT(BTree *pBtree, BTreeNodeData data)
{
	int ret = 1;
	int i = 0;
	BTreeNode *pParentNode = NULL;
	BTreeNode *pCurrentNode = NULL;
	
}