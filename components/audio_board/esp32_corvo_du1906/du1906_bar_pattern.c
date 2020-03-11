/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2020 <ESPRESSIF SYSTEMS (SHANGHAI) CO., LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "display_service.h"
#include "periph_ws2812.h"
#include "board_def.h"
#include "string.h"
#include "esp_log.h"

const struct periph_ws2812_ctrl_cfg ws2812_display_pattern[DISPLAY_PATTERN_MAX][WS2812_LED_BAR_NUMBERS] = {
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 0
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLUE,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 1
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_GREEN,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 2
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_CYAN ,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 3
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_PURPLE,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 4
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_YELLOW,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 5
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_WHITE,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 6
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLUE,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 7
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_GREEN ,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 8
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_CYAN,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 9
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_PURPLE,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 10
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_YELLOW,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 11
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_WHITE,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 12
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_GREEN,
            .loop = 0,
            .time_off_ms = 1000,
            .time_on_ms = 100,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 13
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_BLUE,
            .loop = 0,
            .time_off_ms = 1000,
            .time_on_ms = 100,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        }  // 14
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_CYAN,
            .loop = 10,
            .time_off_ms = 1000,
            .time_on_ms = 100,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        }  // 15
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_RED,
            .loop = 10,
            .time_off_ms = 1000,
            .time_on_ms = 100,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 16
    },
    {
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 17
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_PURPLE,
            .loop = 10,
            .time_off_ms = 1000,
            .time_on_ms = 100,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 18
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_YELLOW,
            .loop = 10,
            .time_off_ms = 1000,
            .time_on_ms = 100,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 19
    },
    {
        {
            .mode = PERIPH_WS2812_BLINK,
            .color = LED2812_COLOR_WHITE,
            .loop = 10,
            .time_off_ms = 1000,
            .time_on_ms = 100,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 20
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_BLUE,
            .loop = 5,
            .time_off_ms = 1500,
            .time_on_ms = 1500,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 21
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_GREEN,
            .loop = 5,
            .time_off_ms = 1500,
            .time_on_ms = 1500,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 22
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_CYAN,
            .loop = 5,
            .time_off_ms = 1500,
            .time_on_ms = 1500,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_BLACK,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 23
    },
    {
        {
            .mode = PERIPH_WS2812_FADE,
            .color = LED2812_COLOR_PURPLE,
            .loop = 5,
            .time_off_ms = 2500,
            .time_on_ms = 2500,
        },
        {
            .mode = PERIPH_WS2812_ONE,
            .color = LED2812_COLOR_RED,
            .loop = 0,
            .time_off_ms = 0,
            .time_on_ms = 0,
        } // 24
    }
};

int8_t get_ws2812_gpio_pin(void)
{
    return WS2812_LED_GPIO_PIN;
}

int get_ws2812_num(void)
{
    return WS2812_LED_BAR_NUMBERS;
}

void ws2812_pattern_copy(struct periph_ws2812_ctrl_cfg *p)
{
    ESP_LOGD("ws2812_pattern_copy", "has been called, %s %d", __FILE__, __LINE__);
    memcpy(p, ws2812_display_pattern, sizeof(ws2812_display_pattern));
}
