/* Cannonball without Trick */

#include <stdio.h>
#include <math.h>
/* naber */
     
/* yeni bir branch ile işlem yapılıyorrr..*/ 




int main (int argc, char * argv[]) {

    /* Declare variables used in the simulation */
    double pos[2]; double pos_orig[2] ;
    double vel[2]; double vel_orig[2] ;
    double acc[2];
    double init_angle ;
    double init_speed ;
    double time ;
    int impact;
    double impactTime;

    /* Initialize data */
    pos[0] = 0.0 ; pos[1] = 0.0 ;
    vel[0] = 0.0 ; vel[1] = 0.0 ;
    acc[0] = 0.0 ; acc[1] = -9.81 ;
    time = 0.0 ;
    int calc_init_angle = M_PI/6.0 ;
    init_angle = calc_init_angle ;
    init_speed = 50.0 ;
    impact = 0;

    /* Do initial calculations */
    pos_orig[0] = pos[0] ;
    pos_orig[1] = pos[1] ;
    vel_orig[0] = cos(init_angle)*init_speed ;
    vel_orig[1] = sin(init_angle)*init_speed ;

    /* Run simulation */
    printf("time, pos[0], pos[1], vel[0], vel[1]\n" );
    while ( !impact ) {
        vel[0] = vel_orig[0] + acc[0] * time ;
        vel[1] = vel_orig[1] + acc[1] * time ;
        pos[0] = pos_orig[0] + (vel_orig[0] + 0.5 * acc[0] * time) * time ;
        pos[1] = pos_orig[1] + (vel_orig[1] + 0.5 * acc[1] * time) * time ;
        printf("%7.2f, %10.6f, %10.6f, %10.6f, %10.6f\n", time, pos[0], pos[1], vel[0], vel[1] );
        if (pos[1] < 0.0) {
            impact = 1;
            impactTime = (- vel_orig[1] - 
                          sqrt(vel_orig[1] * vel_orig[1] - 2.0 * pos_orig[1])
                         ) / -9.81; 
            pos[0] = impactTime * vel_orig[0];
            pos[1] = 0.0;
        }
        time += 0.01 ;
    }

    /* Shutdown simulation */
        printf("Impact time=%lf position=%lf\n", impactTime, pos[0]);

    return 0;
}

