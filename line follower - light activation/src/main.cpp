#include <kipr/wombat.h>

#define lightSensor 0
#define colorSensor 1


int main()
{

    int isActivated = 0;
    //light activation
    while(1) {
        if (isActivated == 1) break;
        printf("light: %d\n", analog(lightSensor));
        motor(0, 0);
        motor(1, 0);
        if (analog(lightSensor) <= 1000) {
            isActivated = 1;
        }

        //get color
        int farbe = analog(colorSensor);
        //on white turn left
        if(farbe > 900) {
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