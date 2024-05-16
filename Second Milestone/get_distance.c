#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <get_distance.h>

float get_distance(float current_long,float current_lat,float next_long,float next_lat)
{

float deg_1 =todeg(current_long);
     float  current_long_rad =torad(deg_1);


    float deg_2=todeg(current_lat);
    float current_lat_rad=torad(deg_2);


    float deg_3=todeg(next_long);
    float next_long_rad=torad(deg_3);

    float deg_4=todeg(next_lat);
    float next_lat_rad=torad(deg_4);




    float longdiff=next_long_rad-current_long_rad;
    float latdiff=next_lat_rad-current_lat_rad;

    float a=pow(sin(latdiff/2),2)+cos(current_lat_rad)*cos(next_lat_rad)*pow(sin(longdiff/2),2);
    float  c=2*atan2(sqrt(a),sqrt(1-a));
    return 6371000*c;
}
