#ifndef MOTOR_H
#define MOTOR_H


typedef struct{
    float inertia; /*kg*m^2*/
    float friction; /*N*m*s/rad*/
    float angle; /*rad*/ 
    float velocity; /*rad/s*/
}motor_t;

void motor_init (motor_t *motor, float inertia, float friction);
void motor_step (motor_t *motor, float torque, float dt);

#endif
