#include  "SqList.h"
#include <stdio.h>
#include <stdlib.h>

Status SqList :: InitList () {
	elem = (ElemType *) malloc (LIST_INIT_SIZE* sizeof (ElemType));
	if(!elem) exit(OVERFLOW);
    length = 0;
	listsize = LIST_INIT_SIZE; //100
	return OK;
}

//销毁
Status SqList :: DestroyList () {
    free (elem);
    return OK;
}

//清空
Status SqList :: ClearList () {
    length = 0;
    return OK;
}

//空表
Status SqList :: ListEmpty () {
    if (length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

//表长
int SqList :: ListLength() {
	
    return length;

}

//读取
Status SqList :: GetElem(int i, ElemType& e) {
 if (i < 1 || i > length) return ERROR;
    e = elem[i];
 	//e = elem[i - 1];
 	return OK;
}

//查找
/*
int SqList :: LocateElem (ElemType e) {
	ElemType *p;
    //int i = 1;
	int i = 0;
	p = elem;
	while (i <= length && (*p != e)) {
        ++i;
		p++;
	}
	if (i <= length) {
		return i;
	} else {
		return 0;
	}
}
*/
/*优化*/
int SqList :: LocateElem (ElemType e) {
    Status left = 0, right = length, mid;// = (left + right) >> 1;
    //sort (data, data + length); //排序
    while (left <= right) {
        mid = (left + right) >> 1;
        if (e == elem[mid]) return mid;
        else if (e < elem[mid]) right = mid;
        else left = mid + 1;//if (e > elem[mid])
    }
    return FALSE;//-1;
}

//插入
Status SqList::ListInsert(int i, ElemType e) { 
	ElemType *newbase, *q, *p;

	if (i < 1 || i > length + 1) return ERROR;
    if (length >= listsize){
	newbase = (ElemType *) realloc (elem, (listsize + LISTINCREMENT) * sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
	elem = newbase;
    listsize = listsize + LISTINCREMENT; //10
	}
  	q = &(elem[i - 1]);
  	for (p = &(elem[length - 1]); p >= q; p--)
		*(p + 1) = *p;
  	*q = e;
  	length++;
  
    return OK;
}

//删除
Status SqList :: ListDelete (int i, ElemType& e) {
	ElemType *newbase, *q, *p;
	if ((i < 1) || (i > length)) return ERROR;
	p = &(elem[i - 1]);
	e = *p;
	q = elem + length - 1;
	for (++p; p <= q; ++p) {
		*(p -1) = *p;
	}
	--length;
	return OK;
}

