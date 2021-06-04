//
//  main.c
//  Ex3
//
//  Created by Kyungeun on 2020/09/20.
//  Copyright © 2020 Kyungeun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 20000 // n의 크기 전역변수

void print_arr(double arr[]){
    for(int i=0;i<n;i++)
        printf("%.3lf ",arr[i]);
    printf("\n");
}

void select_sort(double arr[]){
    int t,i,j;
    double min,tmp;
    for(i=0;i<n;i++){
        t=0; // 최솟값 변동여부 파악하기 위한 변수
        min=arr[i]; // arr[i]를 우선 최솟값으로 지정
        for(j=i+1;j<n;j++){
            if(min>arr[j]){ // min보다 작은 값이 있으면 최솟값 변동
                min=arr[j];
                t=j; // 변동 있음을 알려주는 변수
            }
        }
        if(t!=0){ // 변동이 있다면 swap
            tmp=arr[i];
            arr[i]=arr[t];
            arr[t]=tmp;
        }
    }
}

void bubble_sort(double arr[]){
    int i,j;
    double tmp;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){ // 정렬된 부분을 제외하고 반복
            if(arr[j]>arr[j+1]){ // swap
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}

void insert_sort(double arr[]){
    int i,j;
    double tmp;
    for(i=0;i<n-1;i++){
        for(j=i;j>=0;j--){ // 정해진 구역까지 반복
            if(arr[j]>arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}

void merge(double arr[], int start, int middle, int end){
    double tmp[n]; // 임시배열
    int i=start, j=middle+1, k=0;
    while(i<=middle && j<=end){ // 양쪽 배열까지 반복
        if(arr[i]<=arr[j]) tmp[k++]=arr[i++];
        else tmp[k++]=arr[j++];
    }
    while(i<=middle) tmp[k++]=arr[i++]; // 첫번째 배열값 복사
    while(j<=end) tmp[k++]=arr[j++]; // 두번째 배열값 복사
    for(i=start,j=0;i<=end;i++,j++) arr[i]=tmp[j]; // 임시 -> 원래 배열
}

void merge_sort(double arr[], int start, int end){
    int middle;
    if(start<end){
        middle=(start+end)/2;
        merge_sort(arr, start, middle); // 왼쪽 절반 재귀
        merge_sort(arr, middle+1, end); // 오른쪽 절반 재귀
        merge(arr, start, middle, end); // merge로 합병
    }
}

int quick(double arr[], int start, int end){
    int i=start,j=end+1;
    double p=arr[start],tmp;
    do{
        do{
            i++;
        } while(arr[i]<p && i<=end); // a[i]가 피벗보다 작으면 i 증가
        do{
            j--;
        } while(p < arr[j]); // a[j]가 피벗보다 크면 j 감소
        if(i<j){ // i와 j가 교차하지 않으면 swap
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
    }while(i<j);
    arr[start]=arr[j]; // 교차하면 교환
    arr[j]=p;
    return j; // 피벗 위치 반환
}

void quick_sort(double arr[], int start, int end){
    int j; //pivot
    if(start < end){
        j = quick(arr, start, end); // 피벗 기준 분할
        quick_sort(arr, start, j-1); // 피벗 왼쪽
        quick_sort(arr, j+1, end); // 피벗 오른쪽
    }
}

void heap(double arr[],int size){
    int i,child,root;
    double tmp;
    for(i=1;i<size;i++){
        child = i;
        while(child>0){
            root = (child-1)/2;
            if(arr[root]<arr[child]){ // 루트가 자식보다 작으면 swap
                tmp=arr[root];
                arr[root]=arr[child];
                arr[child]=tmp;
            }
            child=root;
        }
    }
}

void heap_sort(double arr[]){
    int i;
    double tmp;
    for(i=n-1;i>=0;i--){ // 값을 빼내고 다시 heap
        tmp=arr[i];
        arr[i]=arr[0];
        arr[0]=tmp;
        heap(arr,i);
    }
}

void arr_reset(double array[],double arr[]){
    for(int i=0;i<n;i++){
        arr[i]=array[i]; // 원본 array을 정렬될 arr로 복사
    }
}

int main(void) {
    srand((unsigned)time(NULL));
    double array[n],arr[n];
    for(int i=0;i<n;i++){
        array[i]= (2*((double)rand() / RAND_MAX)) -1; // -1~1값 생성
    }
    
    clock_t start, fin;
    double d1,d2,d3,d4,d5,d6;
    
    arr_reset(array, arr); // 초기화
    start=clock(); // 시작시간
    select_sort(arr);
    fin=clock(); // 끝난시간
    d1=(double)(fin-start)/CLOCKS_PER_SEC; // 걸린시간 측정
    printf("\nselect_sort : %f초 걸렸습니다.",d1);

    arr_reset(array, arr);
    start=clock();
    bubble_sort(arr);
    fin=clock();
    d2=(double)(fin-start)/CLOCKS_PER_SEC;
    printf("\nbubble_sort : %f초 걸렸습니다.",d2);

    arr_reset(array, arr);
    start=clock();
    insert_sort(arr);
    fin=clock();
    d3=(double)(fin-start)/CLOCKS_PER_SEC;
    printf("\ninsert_sort : %f초 걸렸습니다.",d3);
    
    arr_reset(array, arr);
    start=clock();
    merge_sort(arr,0,n-1);
    fin=clock();
    d4=(double)(fin-start)/CLOCKS_PER_SEC;
    printf("\nmerge_sort : %f초 걸렸습니다.",d4);
    
    arr_reset(array, arr);
    start=clock();
    quick_sort(arr, 0, n-1);
    fin=clock();
    d5=(double)(fin-start)/CLOCKS_PER_SEC;
    printf("\nquick_sort : %f초 걸렸습니다.",d5);
    
    arr_reset(array, arr);
    start=clock();
    heap(arr,n);
    heap_sort(arr);
    fin=clock();
    d6=(double)(fin-start)/CLOCKS_PER_SEC;
    printf("\nheap_sort : %f초 걸렸습니다.",d6);
    
    return 0;
}
