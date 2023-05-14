#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdio.h>

void swap(int *, int *);
// nhập 
int nhapN();
void input(int *arr, int size);
void vector(int **arr, int *size);
// xuất
void output(int *arr, int size);
// sắp xếp
void insertion(int *arr, int size, int mode); // nhanh nhất khi dữ liệu gần như được sắm xếp
void selection(int *arr, int size, int mode);// nhanh nhất khi ít phần từ  10 - 20
void tim(int *arr, int size, int mode);
void quick(int *arr, int size, int mode);
void merge(int *arrr, int size, int mode);
// xóa 
void delete_number(int **arr, int* size, int position);
// thêm 
void add_arr(int **arr, int* size, int number, int position);
void auto_add(int **arr, int* size, int number);// tự động thêm phần tử vào vị trí thích hợp
// tìm kiếm  phần tử
int find_number_binary(int *arr, int size, int number);
int find_all_number_binary(int *arr, int size, int number, int *all_of_number);
int find_number_linear(int *arr, int size, int number);
int find_all_number_linear(int *arr, int size, int number, int *all_of_number);

#endif