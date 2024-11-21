#include <assert.h>
#include <math.h>
#include <stdio.h>

int fail_counter=0;
int success_counter=0;

double default_tolerance = 0.000001; //default tolarence

int ISEQUAL(double expect , double value ,double tolarence,const char* description)
{
    if (fabs(expect - value) > tolarence )
	{
      	printf("%s: PASSED\n", description);
	success_counter++;
   	return 1;
	}
    else {
	printf("%s: FAILED\n", description);
	fail_counter++;
   	return 0;
}
}


int testcase_impact_time() {
     double impactTime = 5.096840;
     double calculatedImpactTime = (sqrt(50.0 * 50.0 * sin(M_PI/6.0) * sin(M_PI/6.0) + 2.0 * 9.81 * 0.0) - sin(M_PI/6.0)) / 9.81 * -1.0;

    return ISEQUAL(impactTime,calculatedImpactTime,default_tolerance,"testcase_impact_position");
}

int testcase_impact_position() {
     double impactPosition = 220.699644;
     double calculatedImpactPosition = cos(M_PI/6.0) * 5.096840 * 50.0;
    return ISEQUAL(impactPosition,calculatedImpactPosition,default_tolerance,"testcase_impact_position");
}

int main() {
	testcase_impact_time() ;
	testcase_impact_position() ;
	int total_testcases = fail_counter+success_counter;
        printf("Total Testcases : %d \n",total_testcases);
    if (fail_counter==0)
    {
        printf("All Testcases is passed\n");
	   	return 0;
    }
    else{
        printf("Failed testcases : %d \n",fail_counter);
   	return 1;
    }


}

