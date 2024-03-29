#include <iostream>
#include <string>
#include <vector>
#include <valarray>
#include "Population.h"
using namespace std;

int main()  {

Person Joe;
int step = 0;
int n = 0;

    
while (!Joe.is_stable())  {

n = Joe.update();

    
  float bad_luck = (float) rand()/(float)RAND_MAX;
  if (bad_luck>.95) {
    n = Joe.infect(5);
  }

  step = Joe.set_step(step = step + 1);

  if (n == 0)  {
    cout << "On day " << step << ", Joe is " << Joe.status_string() << endl;
  }  else  {
    cout << "On day " << step << ", Joe is " << Joe.status_string() << " (" << n << " to go)" << endl;
  }

  }
};
