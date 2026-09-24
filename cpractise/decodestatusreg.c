/*
Problem Statement
An automotive ECU receives a fault register:
Bit0 = Low battery
Bit1 = Over temperature
Bit2 = CAN bus error
Bit3 = Flash corruption
Bit4 = Sensor disconnected
Bit5 = Watchdog reset
Example:
uint32_t status = 0x25;
Output:
Low battery
CAN bus error
Watchdog reset
Write:
void decode_faults(uint32_t status);
Follow-up:
Count total active faults without looping through all 32 bits.
Expected discussion:
Brian Kernighan algorithm
*/
#include <stdio.h>
#include <stdint.h>

enum status {
    LOWBATTERY=1,
    OVERTEMPERATURE=2,
    CAN_BUS_ERROR=4,
    FLASH_CORRUPTION=8,
    SENSOR_DISCONNECTED=16,
    WATDOG_RESET=32
    };

void decode_faults(uint32_t status);
int main() {
    uint32_t status = 0x25;
    decode_faults(status);
}


void decode_faults(uint32_t status)
{
    /* check if low battery */
    if((status & LOWBATTERY)==LOWBATTERY)
    {
        printf("Low Battery\n");
    }
    if((status & OVERTEMPERATURE)==OVERTEMPERATURE)
    {
        printf("Over Temperature\n");
    }
    if((status & CAN_BUS_ERROR)==CAN_BUS_ERROR)
    {
        printf("Can Bus Error\n");
    }
    if((status & FLASH_CORRUPTION)==FLASH_CORRUPTION)
    {
        printf("Flash Corruption\n");
    }
    if((status & SENSOR_DISCONNECTED)==SENSOR_DISCONNECTED)
    {
        printf("Sensor disconnected\n");
    }
    if((status & WATDOG_RESET)==WATDOG_RESET)
    {
        printf("Watchdog Reset\n");
    }
}
