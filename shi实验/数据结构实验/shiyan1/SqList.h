#include <algorithm>
#include "status.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

class SqList{
	private:
		ElemType *elem;
		int length;
		int listsize;
	public:
		Status InitList (); //
		Status DestroyList ();//
		Status ClearList ();//
		Status ListEmpty ();//
		int ListLength (); //
		Status GetElem (int i, ElemType& e); //
		int LocateElem (ElemType e);//
		Status ListInsert (int i, ElemType e); //
		Status ListDelete (int i, ElemType& e); //
        //Status Traverse (L, visit ());
};

