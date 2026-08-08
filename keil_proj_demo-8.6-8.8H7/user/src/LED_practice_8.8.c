/* LED 按编号闪烁不同次数：LED1 闪 1 次、LED2 闪 2 次……

要求：

至少用到一个函数、一个循环、一个判断；*/

#include "main.h"
#include "gpio.h"
#include "buzzer.h"   /* 蜂鸣器驱动的函数声明 */
#include "led.h"      /* LED 驱动的函数声明 */
#define LED_COUNT   4U    /* 板载 LED 数量，U 表示 unsigned 无符号数 */
#define DELAY_MS    250U  /* LED 亮/灭持续时间，单位毫秒 */
#define BEEP_MS     120U  /* 蜂鸣器响一声的时长 */

// 思路：以led_num为循环条件，blink_led为被循环函数，led_num 与 times同步自增


void practice_blink_led(uint8_t led_num)
{

  /* if 判断：LED 编号只允许 1~4 */
  if (led_num > LED_COUNT)
  {
    return; /* return 直接结束当前函数 */
  }
  for(uint8_t i = 0; i < LED_COUNT; i++)
    {
      led_on(led_num);          /* 点亮指定 LED */
      HAL_Delay(100);      /* 延时一段时间 */
      led_off(led_num);         /* 熄灭指定 LED */
      HAL_Delay(100);
  }
}

void LED_Practice_Test(void)
{
    uint8_t  current_led = 1U;              /* 当前要操作的 LED 编号 */
    uint16_t blink_times = 1;               /* 每颗 LED 闪烁次数 */
    uint32_t delay_ms    = DELAY_MS;    	/* 亮/灭延时 */
    const uint8_t led_count = LED_COUNT;    /* const 表示该变量不允许修改 */
	
    for(current_led = 1U; current_led <= LED_COUNT; current_led++)
    {
        practice_blink_led(current_led);
        blink_times++;
    }
}