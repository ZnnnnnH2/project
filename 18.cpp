#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;

int main()
{
   double t=1;
   for(int i=1;i<=100;i++)
   {
      t=t*i;
      printf("%lf\n",t);
   }
   return 0;
}
