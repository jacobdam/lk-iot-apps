#include <app.h>
#include <kernel/timer.h>
#include <kernel/thread.h>
#include <dev/gpio.h>
#include <target/gpioconfig.h>
#include <lk/debug.h>

typedef const struct app_descriptor app_t;
typedef enum handler_return err_e;

#define LED_DELAY 100
static short led_state = 1;

static err_e led_timer_cb(timer_t *timer, lk_time_t now, void *arg) {

  // Change LED state
  gpio_set(GPIO_LED0, led_state);
  led_state = led_state == 1 ? 0 : 1;

  // Start one-shot timer
  timer_set_oneshot(timer, LED_DELAY, led_timer_cb, NULL);

  return 0;
}

static void blink_init(app_t *app) {
  gpio_config(GPIO_LED0, GPIO_OUTPUT);
  dprintf(INFO, "Hello");
}

static void blink_entry(app_t *app, void *args) {

  timer_t led_timer;

  // Initialize and start one-shot timer
  timer_initialize(&led_timer);
  timer_set_oneshot(&led_timer, LED_DELAY, led_timer_cb, NULL);

  // sleep thread forever
  while (1) thread_sleep(INFINITE_TIME);
}

APP_START(blink)
  .init = blink_init,
  .entry = blink_entry,
  .flags = 0,
APP_END
