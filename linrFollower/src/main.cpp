/* line follower - light activation
* if possible maybe deactivate it again with light
* that way you dont gotta chase it when it runs away
*/
#include <kipr/wombat.h>

#define light_sensor_port 2
#define color_sensor_port 1
#define hand_servo_port 0
#define arm_servo_port 1
#define crash_sensor_port_front 0
#define crash_sensor_port_back 1 

int main()
{

    int isActivated = 0;
    while(1) {
        //light activation
        while(1) {
			if (isActivated == 1) break;
            motor(0, 0);
            motor(1, 0);
            if (light_sensor_port <= 1000) {
                isActivated = 1;
                printf("light: %d\n", analog(2));
            }
        }
        //get color
        //on white turn left
        if(color_sensor_port > 3500) {
            motor(0, 0);
            motor(1, 50);
            //on black turn right
        } else {
            motor(0, 50);
            motor(1, 0);
        }
        //msleep(100);
    }


    return 0;
}