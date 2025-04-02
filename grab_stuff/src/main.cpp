#include <kipr/wombat.h>

#define hand_servo_port 1
#define arm_servo_port 0


int main()
{ 
    enable_servos();
    set_servo_position(arm_servo_port, 1413);
    msleep(1000);
    motor(0, 100);
    motor(1,100);
    motor(arm_servo_port, 100);
    msleep(1000);
    set_servo_position(hand_servo_port, 0);
    msleep(1000);
    set_servo_position(hand_servo_port, 300);
    msleep(1000);
    set_servo_position(arm_servo_port, 0);
    msleep(1000);
    set_servo_position(arm_servo_port, 800);
    msleep(100);
    set_servo_position(hand_servo_port, 300);
    msleep(100);
    disable_servos();
    return 0;
}