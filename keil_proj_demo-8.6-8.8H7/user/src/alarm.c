#include "main.h"
#include "gpio.h"
#include "buzzer.h"   /* 蜂鸣器驱动的函数声明 */
#include "led.h"      /* LED 驱动的函数声明 */


/* #define 是宏定义：编译前会把名字替换成后面的内容 */
#define LED_COUNT   4U    /* 板载 LED 数量，U 表示 unsigned 无符号数 */
#define BLINK_TIMES 5U    /* 每颗 LED 闪烁次数 */
#define DELAY_MS    250U  /* LED 亮/灭持续时间，单位毫秒 */
#define BEEP_MS     30U  /* 蜂鸣器响一声的时长 */


void practice_blink_led(uint8_t led_num , uint8_t blink_times, uint32_t delay_ms)
{


  if (led_num > LED_COUNT)
  {
    return; /* return 直接结束当前函数 */
  }
  for(uint8_t i = 0; i < blink_times; i++)
    {
      led_on(led_num);          /* 点亮指定 LED */
      HAL_Delay(500);      /* 延时一段时间 */
      led_off(led_num);         /* 熄灭指定 LED */
      HAL_Delay(500);
  }
}

void beep(uint32_t beep_ms)
{
  buzzer_on();          /* 打开蜂鸣器 */
  HAL_Delay(beep_ms);   /* 保持响一段时间 */
  buzzer_off();         /* 关闭蜂鸣器 */
}

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
