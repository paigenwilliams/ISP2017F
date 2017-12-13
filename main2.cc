
#include <iostream>
#include <string>
#include <vector>
#include <valarray>
#include "Population.h"
using namespace std;

int main()  {

Population population;
Person Joe;
int npeople = 10;
int step = 0;
population.set_population(npeople);    
    
while (!population.is_pop_stable())  {

population.pop_update();
    
  float bad_luck = (float) rand()/(float)RAND_MAX;
  if (bad_luck>.95) {
    population.random_infection();
  }

  cout << "In step " << step << ", # sick: " << population.count_infected() << " : ";

  population.print();

  cout << " " << endl;

  step = Joe.set_step(step+1);

  }
};
