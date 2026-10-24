#include "motor.h"

void motor_init(motor_t *motor, float inertia, float friction){
    motor->angle = 0;
    motor->velocity = 0;
    motor->inertia = inertia;
    motor->friction = friction;
}

void motor_step(motor_t *motor, float torque, float dt){
    float friction_torque = motor->friction * motor->velocity;
    float accel = (torque - friction_torque) / motor->inertia;
    motor->velocity += accel * dt;
    motor->angle += motor->velocity * dt;
}