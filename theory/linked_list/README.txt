cấu trúc 1 nốt của danh sách liên kết đơn

struct node{
    int data;
    struct node *pNext;
};

typepdef struct node node;

struct pHead{
    node pNode;
}

vì sao hàm "khoitaonode" không viết 
    node newNode() {
    node x;
    printf("nhap gia tri node : ");
    scanf("%d", &x.data);
    x.pNext = NULL;
    return x;
    }
        vì nếu viết như thế thì sẽ cần khai báo biến trước mà khai báo trước thì cần khai báo thêm mảng 
        nhưng thế thì không khác gì mấy 
vì sao cần khai báo con trỏ : vì mỗi lần lặp có thể tự cấp phát thêm bộ nhớ 
