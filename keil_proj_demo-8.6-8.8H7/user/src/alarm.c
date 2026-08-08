#include "main.h"
#include "gpio.h"
#include "buzzer.h"   /* 蜂鸣器驱动的函数声明 */
#include "led.h"      /* LED 驱动的函数声明 */

/* #define 是宏定义：编译前会把名字替换成后面的内容 */
#define LED_COUNT   4U    /* 板载 LED 数量，U 表示 unsigned 无符号数 */
#define BLINK_TIMES 5U    /* 每颗 LED 闪烁次数 */
#define DELAY_MS    250U  /* LED 亮/灭持续时间，单位毫秒 */
#define BEEP_MS     120U  /* 蜂鸣器响一声的时长 */

void alarm_sys_func(uint8_t led_num, uint8_t mode)
{
    if(led_num > LED_COUNT)
    {
        return;
    }
    switch(mode)
    {
        case 0 : // 运行模式
        practice_blink_led(led_num, BLINK_TIMES, DELAY_MS);
        break;
        
        case 1 : // 报警模式
        for(uint16_t delay_ms = 250U; delay_ms >= 100U; delay_ms -= 20U)
        {
            practice_blink_led(led_num, BLINK_TIMES, delay_ms);
            beep(BEEP_MS);
        }
        break;
        
        default:
        break;

    }
}
