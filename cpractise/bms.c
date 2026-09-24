/*
Scenario
A Battery Management System sends a compact telemetry packet.
Bits[0:11]   Voltage
Bits[12:19]  Current
Bits[20:23]  Temperature
Bits[24:31]  Battery ID
Packet value: 0xA53CD2EF
ask

Extract:

Voltage
Current
Temperature
Battery ID
*/

#include <stdio.h>
#include <stdint.h>

#define READ_REG(reg , start, end) do { \
    printf("reg:%x, start:%d, end:%d ", reg, start, end); \
    typeof(reg) mask = (( 1 << ( end - start ) + 1 ) -1 ); \
    printf("mask:%x\n", mask) ; \
    typeof(reg) val = ((reg >> start) & (uint32_t)mask); \
    printf("val:%x\n", val) ; \
    return val; \
} while (0) 



static uint32_t ReadValue(uint32_t reg, uint32_t start, uint32_t end);

int main()
{
    const uint32_t packet =  0xA53CD2EF;
    uint32_t voltage = ReadValue(packet, 0,11);
    uint32_t current = ReadValue(packet, 12,19);
    uint32_t temperature = ReadValue(packet, 20,23);
    uint32_t batteryID = ReadValue(packet, 24,31);

    printf("voltage:%x\n", voltage);
    printf("current:%x\n", current);
    printf("temperature:%x\n", temperature);
    printf("batteryID:%x\n", batteryID);
}

static uint32_t ReadValue(uint32_t reg, uint32_t start, uint32_t end)
{
    READ_REG(reg, start, end);
}

