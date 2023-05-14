#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* pNext; // con trỏ pNext trỏ đến biến kiểu dữ liệu chính nó(struc node là kiểu dữ liệu)
};
typedef struct node node;

struct list
{
    node* pHead;// tức là con trỏ kiểu 'node' dùng để trỏ đến con trỏ khác
    node* pTail;
};
typedef struct list list;
void khoiTao(list* l) {//con trỏ dùng để tham chiếu
    l->pHead = NULL;
    l->pTail = NULL;
}

node* khoiTaoNode(int data) { // khởi tạo một node mới có giá trị mới;
    node* x = (node*)malloc(sizeof(node)); // cấp phát bộ nhớ cho node 
    if (x == NULL) { // xét trường hợp hết ram
        printf("khong du bo nho!!!\n");
        return NULL;
    }
    x->data = data; // gán giá trị đầu vào
    x->pNext = NULL;
    return x;
}

// con trỏ l là tham chiếu, còn con trỏ bản thân nó là con trỏ đc cấp phát động
void ThemVaoDau(list* l, node* p) { // thêm node mới vừa khởi tạo vào đầu danh sách
    if (l->pHead == NULL) {// danh sách đang rỗng 
        l->pHead = l->pTail = p;
    }
    else {
        p->pNext = l->pHead;//cho node mới trỏ vào node trước đó
        l->pHead = p;// đổi vị trí node vừa nhập thành node đầu
    }
}

void ThemVaoCuoi(list* l, node* p) { // thêm node mới vừa khởi tạo vào cuối danh sách
    if (l->pHead == NULL) {
        l->pTail = l->pHead = p;
    }
    else {
        l->pTail->pNext = p; 
        l->pTail = p;
    }
}

void xuatDanhSach(list l) {
    for (node* p = l.pHead; p != NULL; p = p->pNext) {
        printf("%-5d", p->data);
    }
}

int main() {
    int x;
    node *p;
    list l;
    khoiTao(&l);

    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        p = khoiTaoNode(x); 
        ThemVaoDau(&l, p);
    }
    printf("\n\n\t\tDANH SACH LIEN KET DON \n");
    xuatDanhSach(l);
    free(p);
    
    return 0;
}