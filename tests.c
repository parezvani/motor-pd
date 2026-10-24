#include <stdio.h>
#include "motor.h"
#include "pd.h"

// counters for the summary at the end
static int passed = 0;
static int failed = 0;

// CHECK(name, condition): prints ok or FAIL and counts it
#define CHECK(name, cond) do {                         \
    if (cond) { passed++; printf("  ok    %s\n", name); } \
    else      { failed++; printf("  FAIL  %s\n", name); } \
} while (0)

int main(void) {
    // rule: pushing a motor that's at rest makes it move forward
    motor_t m;
    motor_init(&m, 0.01, 0.1);
    motor_step(&m, 0.5, 0.001);
    CHECK("motor: positive torque moves it forward", m.velocity > 0);


    //rule 1: target ahead of the motor -> torque is positive
    pd_t p;
    pd_init(&p, 2, 0.1, 1);
    pd_set_target(&p, 1);
    float torque = pd_update(&p, 0, 0);
    CHECK("positive torque: target ahead of the motor so torque is positive", torque > 0);
    

    //rule 2: target behind the motor -> torque is negative
    pd_set_target(&p, 0);
    torque = pd_update(&p, 1, 0);
    CHECK("negative torque: target behind the motor so torque is negative", torque < 0);
    

    //rule 3: huge error -> torque never goes past max_torque
    pd_set_target(&p, 3);
    torque = pd_update(&p, 20, 0);
    CHECK("clamp: torque never goes past the limit", -1 <= torque && torque <= 1);

    //rule 4: at the target and not moving -> torque is 0

    printf("\n%d passed, %d failed\n", passed, failed);
    return failed != 0;
}
