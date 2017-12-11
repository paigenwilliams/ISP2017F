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
float probability = population.set_probability_of_transfer();
population.set_population(npeople);
population.number_immune();

while (step < 10)  {

population.pop_update();

    float bad_luck = (float) rand()/(float)RAND_MAX;
    if (bad_luck>.5) {
      population.random_infection();
    }

  population.transfer(probability);

  cout << "In step " << step << ", # sick: " << population.count_infected() << " : ";

  population.print();

  cout << " " << endl;

  step = Joe.set_step(step+1);

  }
};
