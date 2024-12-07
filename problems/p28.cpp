#include <stdio.h>
#include <math.h>

#define MY_ABS(x) x < 0 ? -x : x

// Function to calculate the angle between the hour and minute hands of a clock
int main(void) {
    int ha = 11; // Hour hand position
    int ma = 30; // Minute hand position
        // Adjusting hour and minute values to avoid errors for ha = 12 and ma = 60
    if (ha == 12) 
        ha = 0; 
    if (ma == 60)  
        ma = 0; 

    // Calculate hour and minute angles based on clock readings
    int hour_angle = (int)(0.5 * (ha * 60 + ma)); // Hour hand angle
    int minute_angle = (int)(6 * ma); // Minute hand angle

    // Calculate the absolute difference between hour and minute angles
    int angle = MY_ABS(hour_angle - minute_angle);

    // Calculate the smaller angle between the two possible angles
    int complementary_angle = 360 - angle; // Calculate complementary angle
    return (complementary_angle > angle) ? angle : complementary_angle;
}
