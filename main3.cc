#include <iostream>
#include <string>
#include <vector>
#include <valarray>
#include "Population.h"
using namespace std;

int main()  {

Population population(10);
Person Joe;
int step = 0;
float probability = population.set_probability_of_transfer();

while (!population.is_pop_stable())  {

    float bad_luck = (float) rand()/(float)RAND_MAX;
    if (bad_luck>.95) {
      population.random_infection();
    }

  population.transfer(probability);

  cout << "In step " << step << ", # sick: " << population.count_infected() << " : ";

  population.print();

  cout << " " << endl;

  step = Joe.set_step(step+1);

  }
};
