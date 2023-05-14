#include <stdio.h>

int main(int soLuongChuoiDuocDuaVaoLucChayexe, int** mangChuoiDuaVao) {

    //là 1 số bắt đầu từ 1
    printf("%d", soLuongChuoiDuocDuaVaoLucChayexe);
    //phần tử 0 của mảng là địa chỉ file .exe
    //phần tử 1-> là chuỗi được đưa vào 
    printf("\n%s\n%s", mangChuoiDuaVao[0], mangChuoiDuaVao[1]);

}