#include "Population.h"
#include <iostream>
#include <string>
using namespace std;


Person::Person(string s, int si, int stp, int ni, int np)
  : status_int(si), status(s), step(stp), n(ni), npeople(np)  {
  si = 0;
  status_int = 0;
};


void Person::set_person(string s, int si, int stp, int ni, int np)  {
    s = status;
    si = status_int;
    stp = step;
    ni = n;
    np = npeople;
};


string Person::status_string()  {
    if (status_int == 0)  {
      status =  "susceptible";
    }
    if (status_int == -1)  {
      status = "recovered";
    }
    if (status_int == -2 && n == 0)  {
      status = "inoculated";
    }
    if (n != 0)  {
      status = "sick";
    }
  return status;
};


int Person::get_status()  {
   return status_int;
};


void Person::set_status(int s_int)  {
  status_int = s_int;
};

int Person::update()  {
    if (n != 0)  {
      status_int = -1;
      n--;
    }
  return status_int;
};


int Person::infect(int newn)  {
  if (status_int == 0)  {
    n = newn;
    status_int = n;
  }
  return n;
};


int Person::set_step(int newstep)  {
  step = newstep;
  return step;
};


bool Person::is_stable()  {
  if (status_int == -1 &&  n == 0)  {
    return  true;
  }
  if (status_int == -2)  {
    return true;
  }
  else  {
    return false;
  }
};
