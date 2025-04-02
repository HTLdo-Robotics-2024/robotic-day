#include <kipr/wombat.h>

#define light_sensor_port 2
#define color_sensor_port 1
#define hand_servo_port 0
#define arm_servo_port 1
#define crash_sensor_port_front 0
#define crash_sensor_port_back 1 


//spinny
int main()
{

    while(1){
        if(light_sensor_port < 300){
            break;
        }
    }

    enable_servos();
    set_servo_position(hand_servo_port,300);
    disable_servos();

    motor(0,100);
    motor(1,100);


    while(1){
        //360 Drehung wenn vorderer Button     
        if(digital(crash_sensor_port_front) == 1){
            motor(0,-100);

            motor(1,100);
            msleep(3000);
        }

        //weiter fahren   
        motor(0,100);
        motor(1,100);

        //stop wenn taster hinten     
        if(digital(crash_sensor_port_back)==1){
            break;}
    }

    return 0;
}
