#include "udf.h"

DEFINE_ZONE_MOTION(motion, omega, axis, origin, velocity, time, dtime)
{
    if (time < 60)
    {
        time = CURRENT_TIME;
        *omega = 0.096 * cos(time);  // Rotational velocity function
    }

    // Set velocity to zero in all directions
    NV_D(velocity, =, 0.0, 0.0, 0.0);
    
    // Set origin to zero for all axes
    NV_S(origin, =, 0.0, 0.0, 0.0);
    
    // Set rotation axis to the z-axis
    NV_D(axis, =, 0.0, 0.0, 1.0);

    return;
}
