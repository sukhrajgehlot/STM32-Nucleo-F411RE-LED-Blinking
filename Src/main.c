
#include <stdint.h>

int main(void)
{
    uint32_t *AHB1ENR = (uint32_t*)0x40023830;
    uint32_t *MODER   = (uint32_t*)0x40020000;
    uint32_t *ODR     = (uint32_t*)0x40020014;

    // Enable GPIOA clock
    *AHB1ENR |= 0x01;

    // Configure PA5 as output
    *MODER &= 0xFFFFF3FF;
    *MODER |= 0x00000400;

    while (1)
    {
        // Turn LED ON
        *ODR |= 0x20;

        // Delay
        for (volatile uint32_t i = 0; i < 500000; i++);

        // Turn LED OFF
        *ODR &= ~0x20;

        // Delay
        for (volatile uint32_t i = 0; i < 500000; i++);
    }
}
