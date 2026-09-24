/*
A microcontroller has a 32-bit GPIO configuration register
Each pin uses 2 bits:
00 = Input
01 = Output
10 = Alternate Function
11 = Analog
Implement:
void set_gpio_mode(uint32_t *reg,
                   uint8_t pin,
                   uint8_t mode);
Initial register value : 00000000

Configure pin 5 as Alternate Function:
set_gpio_mode(&reg, 5, 2);
Bits [11:10] = 10
*/



#include <stdio.h>
#include <stdint.h>

enum operation {
    INPUT=0,
    OUTPUT=1,
    ALTERNATE=2,
    ANALOG=3,
    };

#define WRITE_REG(reg, mode, start, end) do { \ 
    typeof(reg) mask = (1U << ( end - start + 1U)) - 1U; \
    reg &= ~(mask << start); \
    reg |= ((mode & mask) << start); \
} while(0);

void set_gpio_mode(uint32_t* reg, uint8_t pin, uint8_t mode)
{
    if( pin > 15)
        return ;

    uint32_t Reg=*reg;
    const uint32_t start =  pin * 2U ;
    const uint32_t end = start + 1U;
    printf("start:%d end:%d\n", start, end);
    printf("reg:%08x\n", *reg);
    WRITE_REG(Reg, mode, start, end)
    *reg=Reg;
    printf("reg:%08x\n", *reg);
}

int main() {
    uint32_t reg = 0x00000000;
    set_gpio_mode(&reg,5, ANALOG);
    return 0;
}
