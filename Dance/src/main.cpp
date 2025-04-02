#include <kipr/wombat.h>

#define rightWheel 0
#define leftWheel 1
#define armServo 0
#define handServo 1



int main()
{

    printf("Let's Grove Tonight!\n");

    enable_servos();
    

    while(1) {
        for (int i=0; i<4; i++) {
            mav(leftWheel, 1000);
            mav(rightWheel, 1000);
            msleep(1000/5); 
            set_servo_position(armServo, 1800);
            mav(leftWheel, 250);
            mav(rightWheel, 1000);
            msleep(2600);
            set_servo_position(armServo, 1000);
        }

        mav(leftWheel, 1000);
        mav(1, -1000);
        msleep(1850);
        ao();
        msleep(1500);
        set_servo_position(handServo, 2000); 

        for (int i=0; i<4; i++) {
            set_servo_position(armServo, 1000);
            mav(leftWheel, -1000);
            mav(rightWheel, -1000);
            msleep(1000/5);
            set_servo_position(armServo, 1800);
            mav(leftWheel, -1000);
            mav(rightWheel, 1000);
            msleep(1000);
        }
        mav(leftWheel, -1000);
        mav(rightWheel, -1000);
        msleep(1000/5); 
        ao();
        set_servo_position(handServo, 1000); 
        
    }

    return 0;
}