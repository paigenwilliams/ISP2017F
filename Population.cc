#include "Population.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;


Population::Population(int np)
  : npeople(np) {
  for (int i = 0;i < np;i++)  {
    People.push_back(Person());
    People[i].set_status(0);
  }
};


void Population::number_immune()  {
  int i = 0;
  int immune;
  cout << "Please enter the number of people immune: ";
  cin >> immune;
  while (i < immune)  {
    int x = rand()%npeople;
    if (People[x].get_status() != -2)  {
      People[x].set_status(-2);
      i++;
    }
  }
};


float Population::set_probability_of_transfer()  {
  float probability;
  cout << "Please enter a probability: ";
  cin >> probability;
  return probability;
};


void Population::transfer(float probability)  {
for (int i = 1;i < npeople;i++)  {
  if (!People[i].is_stable() && People[i].get_status() != 0)  {
    if (i != 0)  {
    prob = rand()/(float)RAND_MAX;
      if (prob < probability)  {
        if (People[i-1].get_status() != -1 && People[i-1].get_status() != -2)  {
          People[i-1].infect(5);
        }
      }
    }

    if (i < npeople - 1)  {
    prob = rand()/(float)RAND_MAX;
      if (prob < probability)  {
        if (People[i+1].get_status() != -1 && People[i+1].get_status() != -2)  {
          People[i+1].infect(5);
        }
      }
    }

    }
  }
};


bool Population::is_pop_stable()  {
  for (int i = 0;i <= npeople;i++)  {
    if (!People[i].is_stable())  {
      return false;
        break;
    }
    if (i == npeople+1)  {
      return true;
    }
  }
};



void Population::people_met(float probability, int pm)  {
  float prob;
  vector<int> x(npeople);
  bool duplicate;
  
for (int k = 0;k < npeople;k++)  {  
  for (int i = 0;i < pm;i++)  {
    duplicate = true;
    while (duplicate)  {
      x[i] = rand()%npeople;
        if (i == 0)  {
          duplicate = false;
        }  else  {
        for (int j = i - 1;j > -1;j--)  {
          if (x[i] == x[j])  {
            duplicate = true;
            break;
          }
          if (j == 0 && x[i] != x[j])  {
            duplicate = false;
          }
        }
      }
      if (People[x[i]].get_status() == -1 && !People[x[i]].is_stable())  {
        prob = rand()/(float)RAND_MAX;
        if (prob < probability && People[x[i]].get_status() == 0)  
          People[k].infect(5);
    }
  }
      if (People[k].get_status() == -1 && !People[k].is_stable())  {
        prob = rand()/(float)RAND_MAX;
        if (prob < probability && People[x[i]].get_status() == 0)  {
          People[x[i]].infect(5);

        }
      }
    }
  }
};


void Population::print()  {
  for(int i = 0;i < npeople;i++)  {
   if (People[i].get_status() == 0)  {
      cout << "? ";
    }
    if (People[i].get_status() == -1 && People[i].is_stable())  {
      cout << "- ";
    }
    if (People[i].get_status() == -2)  {
      cout << "* ";
    }
    if (!People[i].is_stable() && People[i].get_status() == -1)  {
     cout << "+ ";
    }
  }
};


int Population::pop_update()  {
  for (int i = 0; i <= npeople; i++)  {
     People[i].update();
  }
};


void Population::random_infection()  {
    int value = rand()%(npeople + 1);
    People[value].infect(5);
};


int Population::count_infected()  {
  int ninfected = 0;
  for (int i = 0;i<npeople; i++)  {
    if (People[i].get_status() == -1 && !People[i].is_stable())  {
      ninfected++;
    }
  }
return ninfected;
};
