#ifndef PD_H
#define PD_H

typedef struct{
    float kp;          // push per rad of error
    float kd;          // brake per rad/s
    float max_torque;  // N*m limit
    float setpoint;    // target angle (rad)
}pd_t;

void pd_init(pd_t *pd, float new_kp, float new_kd, float new_max);
float pd_update(pd_t *pd, float angle, float velocity); // returns torque

#endif
