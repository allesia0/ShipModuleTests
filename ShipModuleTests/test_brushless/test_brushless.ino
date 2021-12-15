#include <FaBoPWM_PCA9685.h>
//channel value between 0~4096,0 is 0%, 4096 is 100%
FaBoPWM faboPWM;
int pos = 0;
int MAX_VALUE_SERVO = 1.9/20.0*4096;//2ms
int MIN_VALUE_SERVO = 1.1/20.0*4096;//1ms
int MID_VALUE_SERVO=1.5/20.0*4096;//1.5ms

int MAX_VALUE_MOTOR = 2/20.0*4096;//2ms
int MIN_VALUE_MOTOR = 1/20.0*4096;//1ms
int MID_VALUE_MOTOR=1.5/20.0*4096;//1.5ms
void setup() {
  if(faboPWM.begin()) {
    faboPWM.init(300);
  }
  faboPWM.set_hz(50);
  faboPWM.set_channel_value(4, MAX_VALUE_MOTOR);
  delay(5000);
  faboPWM.set_channel_value(4, MIN_VALUE_MOTOR);
  delay(5000);
}

void loop() {
faboPWM.set_channel_value(6, MIN_VALUE_SERVO);
faboPWM.set_channel_value(5, MIN_VALUE_SERVO);     
faboPWM.set_channel_value(4, MIN_VALUE_MOTOR);     
delay(1000);
faboPWM.set_channel_value(6, MAX_VALUE_SERVO);
faboPWM.set_channel_value(5, MAX_VALUE_SERVO);
faboPWM.set_channel_value(4, MID_VALUE_MOTOR);
delay(1000);   
    
}
