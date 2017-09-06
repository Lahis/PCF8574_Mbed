#include "mbed.h"
DigitalOut debugPin(LED1);
DigitalOut debugPin1(LED2);
I2C i2c(p28, p29);        // sda, scl
Serial pc(USBTX, USBRX); // tx, rx

const int addr = 0x40; // define the I2C Address

int main() {
    char cmd[2];
    
    while(1) {
        debugPin1 = 1;
        cmd[0] = 0x40;            // pointer to command register
        cmd[1] = 0x00;            // pointer to command register
        //i2c.start();
        i2c.write(addr, cmd, 2); // Send command string
        //i2c.stop();
        wait(1); 
        debugPin1 = 0;
        wait(1); 
                     // Could also poll, 65ms is typical

    }
}