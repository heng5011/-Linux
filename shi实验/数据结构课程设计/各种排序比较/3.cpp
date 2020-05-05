/*************************************************************************
	> File Name: 3.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年12月24日 星期二 13时19分28秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include<time.h>
#include <algorithm>
using namespace std;

//插入
void direct(int a[]) {
    int i,j,w;
    for(i = 0; i < 30000; i++) {
        for(j = i; j >= 0; j--) {
            if (a[j] >= a[j + 1]) {
                w = a[j];
                a[j] = a[j + 1];
                a[j + 1] = w;
            }
        }
    }
}

//选择
void choices_sort(int a[]) {
     int i,j,k,t;
    for(i = 0; i < 30000; i++) {
       k = i;
       for (j = i+1; j < 30000; j++) {
            if(a[k]>a[j]) k=j;
            t=a[i];
            a[i]=a[k];
            a[k]=t;
        }
    }
}

//冒泡
void bubble_sort(int a[]) {
    int i,j,w;
    for(i = 0; i < 30000; i++)
        for(j = 0; j < 30000 - i; j++)
            if(a[j] > a[j + 1]) {
                w = a[j];
                a[j] = a[j + 1];
                a[j + 1] = w;
            }
}

//希尔
void shellsort(int a[], int n) {
    int d, i, j, temp;

    for (d = n / 2; d >= 1; d = d / 2) {
        for(i = d; i < n; i++) {
            temp = a[i];
            for(j = i - d; (j >= 0) && (a[j] > temp); j = j - d) {
                a[j + d] = a[j];
            }
            a[j+d]=temp;
        }
    }
}

//快速排序
void sort(int a[], int x, int y) {
     int xx = x, yy = y;
     int k = a[x];
     if (x >= y) return;
     while(xx != yy) {
         while (xx < yy && a[yy] >= k)
            yy--;
          a[xx] = a[yy];
          while(xx < yy && a[xx] <= k)
                xx++;
          a[yy]=a[xx];
    }
    a[xx] = k;
    sort(a, x, xx - 1);
    sort(a, xx + 1, y);
}

//堆
void sift(int *x, int n, int s) {
      int t, k, j;
      t = *(x + s);                                  /*暂存开始元素*/
      k = s;                                       /*开始元素下标*/
      j = 2*k + 1;                                 /*右子树元素下标*/
      while (j < n) {
        if (j < n - 1 && *(x + j) < *(x + j + 1)) {
            j++;
        }
        if (t < *(x + j)) {
          *(x + k) = *(x + j);
          k = j;
          j = 2 * k + 1;
        } else {
            break;
        }
    }
    *(x + k) = t;
}

void heap_sort(int *x, int n) {
    int i, k, t;
    for (i = n / 2 - 1; i >= 0; i--) {
        sift(x, n, i);
    }
    for (k = n - 1; k >= 1; k--) {
        t = *(x + 0);
        *(x + 0) = *(x + k);
        *(x + k) = t;
        sift(x, k, 0);
    }
}

//归并
void Merge(int *R, int low, int m, int high) {
    int i = low, j = m + 1, p = 0;
    int *R1;
    R1 = (int *) malloc((high - low + 1)*sizeof(int));
        if(!R1)
            return;
    while(i <= m && j <= high)
        R1[p++] = (R[i] <= R[j]) ? R[i++] : R[j++];
    while(i <= m)
        R1[p++] = R[i++];
    while(j <= high)
        R1[p++] = R[j++];
    for(p = 0, i = low; i <= high; p++, i++)
        R[i]=R1[p];
}

void MergeSort(int R[], int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        MergeSort(R, low, mid);
        MergeSort(R, mid + 1, high);
        Merge(R, low, mid, high);
    }
}

int main() {
    clock_t start, finish;
    int i, time1, time2, time3, time4, time5, time6, time7;
    int a[30000],b[30000];
    srand(time(0));
	for(i = 0; i < 30000; i++)
        a[i]=rand();
    cout << "\t选择排序\n";
    for(i = 0; i < 30000; i++)
        b[i] = a[i];
    start = clock();
    choices_sort(b);
    finish = clock();
    time1 = finish - start;
    printf("选择排序耗时%d毫秒!\n\n\n",time1);
    cout<<"\t插入排序\n";
    for(i = 0; i < 30000; i++)
        b[i]=a[i];
    start = clock();
        direct(b);
    finish = clock();
    time2 = finish - start;
    printf("直接插入排序耗时%d毫秒!\n\n\n", time2);
    cout << "\t堆排序\n";
    for(i = 0; i < 30000; i++)
        b[i] = a[i];
    start = clock();
    heap_sort(b, 30000);
    finish = clock();
    time3 = finish - start;
    printf("堆排序耗时%d毫秒!\n\n\n", time3);
    cout << "\t快速排序\n";
    for (i = 0; i < 30000; i++)
        b[i] = a[i];
    start = clock();
    sort(b, 0, 29999);
    finish = clock();
    time4 = finish - start;
    printf("快速排序耗时%d毫秒!\n\n\n", time4);
    cout << "\t冒泡排序\n";
    for(i = 0; i < 30000; i++)
        b[i] = a[i];
    start = clock();
    bubble_sort(b);
    finish = clock();
    time5 = finish - start;

    printf("冒泡排序耗时%d毫秒!\n\n\n", time5);
    cout<<"\t希尔排序\n";
    for(i = 0; i < 30000; i++)
        b[i] = a[i];
    start = clock();
    shellsort(b, 30000);
    finish = clock();
    time6 = finish - start;

    printf("希尔排序耗时%d毫秒!\n\n\n",time6);
    cout << "\t归并排序\n";
    for(i = 0; i < 30000; i++)
        b[i] =a [i];
    start = clock();
    MergeSort(b, 0, 29999);
    finish = clock();
    time7 = finish - start;
    printf("归并排序耗时%d毫秒!\n\n\n",time7);
    
    return 0;
}

