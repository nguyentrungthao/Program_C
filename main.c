// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdint.h>

// typedef enum {
//   OK = 0u,
//   BUSY,
//   ERROR,
//   INVAILD
// } result;

// typedef enum {
//   CHS1 = 0u,
//   chs2,
//   ch3
// } chs_type;

// typedef struct {
//   uint16_t* port;
//   uint16_t pin;
// } infoPin;

// typedef struct {
//   infoPin TX, RX;
//   uint8_t data;
// } uart_type;

// uart_type uart1;
// uart_type uart2; 

// result uart_init(uart_type* uart, uint16_t* portTX, uint16_t pinTX, uint16_t* portRX, uint16_t pinRX);
// void log_uart(const uart_type uart);

// int main() {
//   // giải định địa chỉ của port a
//   uint16_t* address_Port_A = (uint16_t*)malloc(sizeof(uint16_t));
//   uint16_t* address_Port_c = (uint16_t*)malloc(sizeof(uint16_t));

//   uart_type* pUart = NULL;

//   uart_init(&uart1, address_Port_A, 10, address_Port_A, 20);
//   log_uart(uart1);
//   uart_init(&uart2, address_Port_c, 33, address_Port_c, 01);
//   log_uart(uart2);

//   pUart = &uart1;
//   pUart->TX.pin = 99;
//   pUart->TX.port = (uint16_t*)100u;
//   log_uart(uart1);


//   free(address_Port_A);
//   free(address_Port_c);
//   return EXIT_SUCCESS;
// }

// result uart_init(uart_type* uart, uint16_t* portTX, uint16_t pinTX, uint16_t* portRX, uint16_t pinRX) {
//   if (uart == NULL) {
//     return INVAILD;
//   }
//   if (portRX == NULL || pinRX == 0) {
//     return INVAILD;
//   }
//   if (portTX == NULL || pinTX == 0) {
//     return INVAILD;
//   }

//   uart->TX.port = portTX;
//   uart->TX.pin = pinTX;

//   uart->RX.port = portRX;
//   uart->RX.pin = pinRX;
//   return OK;
// }

// void log_uart(const uart_type uart) {
//   printf("TX: %p %d", uart.TX.port, uart.TX.pin);
//   printf("\nRX: %p %d\n\n", uart.RX.port, uart.RX.pin);
// }

#include <stdio.h>
#include "./LIB/lib1.h"

int main() {
  Person* p = person_create("John", 30);
  person_set_age(p, 35);
  printf("Age: %d\n", person_get_age(p));
  // Lỗi biên dịch vì không thể truy 
  //cập trực tiếp đến biến age
  p->age = 15;
  person_destroy(p);
  return 0;
}
