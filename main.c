#include <stdio.h>
#include "motor.h"


int main(void){
    motor_t m;
    motor_init(&m,0.01, 0.1);
    float dt = 0.001;
    for (int i = 0;i < 1000; i++ ){
        motor_step(&m, 0.5, dt);
        printf("%d, %f, %f\n", i, m.angle, m.velocity);

    }
    return 0;
}
