/*
    struct tm {
        int tm_sec;         //biểu diễn giây, từ 0 tới 59 
        int tm_min;         //biểu diễn phút, từ 0 tới 59 
        int tm_hour;        // biểu diễn giờ, từ 0 tới 23  
        int tm_mday;        // biểu diễn ngày của tháng, từ 1 tới 31 
        int tm_mon;         // biểu diễn tháng, từ 0 tới 11   
        int tm_year;        // biểu diễn năm, bắt đầu từ 1900 
        int tm_wday;        // ngày trong tuần, từ 0 tới 6    
        int tm_yday;        // ngày trong năm, từ 0 tới 365   
        int tm_isdst;       // biểu diễn Daylight Saving Time 
    };
    time_t time(time_t *t) nếu t là null hàm trả về biến
                            nếu t != null tự cập nhật vào biến t 
    struct tm *localtime(const time_t *timer) nhận vào số giờ hàm time()
        chuyển thành giờ hiện tại
    char *asctime(const struct tm *timeptr) nhận vào 1 con trỏ cấu trúc (struct tm*)
        chuyển dữ liệu trong cấu trúc đó thành 1 chuỗi string trả về địa chỉ của chuỗi string đó
    double difftime(time_t time1, time_t time2) nhận vào 2 biến thời gian(time_t)
        tính sự chênh lệch t2 - t1

*/

#include <stdio.h>
#include <time.h>
// lấy thời gian từ hệ thống (laptop)
void layThoiGian_laptop() {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current local time and date: %s", asctime(timeinfo));
}
// đo thời gian thực thi chương trình 
void doThoiGianThucThi() {
    time_t start_t, end_t;
    double diff_t;

    printf("Bắt đầu chương trình...\n");
    time(&start_t);

    time(&end_t);
    diff_t = difftime(end_t, start_t);

    printf("thoi gian thuc thi = %f\n", diff_t);
    printf("thoat chuong trinh...\n");
}

int main()
{


    return 0;
}