#include "pd.h"

void pd_init(pd_t *pd, float new_kp, float new_kd, float new_max){
    // save settings so pd_update can use them later
    pd->kd = new_kd;
    pd->kp = new_kp;
    pd->max_torque = new_max;
    pd->setpoint = 0;
}

float pd_update(pd_t *pd, float angle, float velocity){
    // push toward target, brake against speed
    float torque = pd->kp * (pd->setpoint - angle) - (pd->kd * velocity);

    // clamp to motor limit
    if(torque > pd->max_torque){ //pos max
        torque = pd->max_torque;
    }else if(torque < -(pd->max_torque)){ // neg max
        torque = -(pd->max_torque);
    }
    return torque;
}

void pd_set_target(pd_t *pd, float target){
    pd->setpoint = target;
}
