#include"SeqList.h"

int main()
{
	SeqList* pHead = NULL;
	SeqList* head = NULL;
	InitList(&pHead);
	InitList(&head);
//////////////////////////////////
	PushBack(&pHead,1);
	PushBack(&pHead,2);
	PushBack(&pHead,3);
	PushBack(&pHead,4);
	PushBack(&pHead,5);
	PushBack(&pHead,6);
	PushBack(&pHead,7);
	PushBack(&pHead,8);
	PushBack(&pHead, 9);
	printf("�ж��Ƿ���ѭ������>%d\n", SeqListFloyd(pHead));
	PushBack(&head, 0);
	PushBack(&head, 2);
	PushBack(&head, 6);
	PushBack(&head, 8);
	PushBack(&head, 10);
	PushBack(&head, 11);
	PushBack(&head, 12);

	/*printf("β��->\n");
	PrintList(pHead);
///////////////////////////////////
	printf("βɾ->\n");
	PopBack(&pHead);
	PrintList(pHead);
///////////////////////////////////
	printf("ͷ��->\n");
	PushFront(&pHead, 0);
	PrintList(pHead);
//////////////////////////////////
	printf("ͷɾ->\n");
	PopFront(&pHead);
	PrintList(pHead);
//////////////////////////////////
	printf("ָ��λ�ò���->\n");
	PopList(&pHead,pHead->_next, 6);
	PrintList(pHead);
//////////////////////////////////
	printf("ָ��λ��ɾ��->\n");
	ListErase(&pHead, pHead->_next);
	PrintList(pHead);*/
///////////////////////////////////
//	printf("��ʼ����>");
//	PrintList(pHead);
//	printf("��β��ͷ��ӡ> ");
//	SLitsPrintTailToHead(pHead);
//	printf("\n");
//////////////////////////////////////////
//	printf("��ʼ����>");
//	PrintList(pHead);
//	printf("ɾ��һ����ͷ������ķ�β�ڵ�>");
//	SListDelNonTailNode(pHead->_next);
//	PrintList(pHead);
///////////////////////////////////////////////
//	printf("��ʼ����>");
//	PrintList(pHead);
//	printf("����ͷ�������һ���ڵ�ǰ����һ���ڵ�>");
//	NoHeadSeqListInsert(&pHead, pHead->_next, 2);
//	PrintList(pHead);
//////////////////////////////////////////////////
//	printf("���õ�����> ");
//	SeqListReverse(&pHead);
//	PrintList(pHead);
///////////////////////////////////////////////
//	printf("ð������> ");
//	SListBubbleSort(pHead);
//	PrintList(pHead);
//////////////////////////////////////////////
//	/*printf("�ϲ���������> ");
//	SListMerge(&pHead,&head);*/
////////////////////////////////////////////
//	printf("Ѱ���м�ڵ�> ");
//	SeqList* pos = SListFindMidNode(&pHead);
//	printf("�м�ڵ�����>%d\n", pos->_data);
//////////////////////////////////////////
//	SeqList* cur=SListFindTailKNode(&pHead, 3);
//	printf("�����������ڵ�����>%d\n", cur->_data);
//	printf("�����������ڵ��ַ>%#p\n", &cur);
//////////////////////////////////////////////
//	printf("��ʼ����> ");
//	PrintList(pHead);
//	printf("ɾ�������������ڵ�> ");
//	DeleteKNode(&pHead, 3);
//	PrintList(pHead);
//	NoHeadSeqListInsert(&pHead, pHead->_next->_next->_next->_next->_next, 6);
	//PrintList(pHead);
	//SeqList* tmp= CircleSListNode(&pHead);
	//printf("��������>%d\n", tmp->_data);
	test11(&pHead);
	system("pause");
	return 0;
}