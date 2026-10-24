#include <stdio.h>
#include "motor.h"
#include "pd.h"


int main(void){
    motor_t m;
    pd_t p;
    motor_init(&m,0.01, 0.1);
    pd_init(&p,2, 0.1, 1);
    pd_set_target(&p, 1);
    float dt = 0.001;
    for (int i = 0;i < 1000; i++ ){
        float torque = pd_update(&p, m.angle, m.velocity);
        motor_step(&m, torque , dt);
        printf("%d, %f, %f, %f\n", i, m.angle, m.velocity, torque);

    }
    return 0;
}
