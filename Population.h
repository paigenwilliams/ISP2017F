using namespace std;


class Person {

private:
  int n;
  int npeople;
  int status_int;
  int step;
  string status;

public:
  Person(string s = "none", int si = 0, int stp = 0, int ni = 0, int np = 10);
  void set_person(string s, int si, int stp, int ni, int np);
  string status_string();
  int get_status();
  void set_status(int s_int);
  int set_step(int newstep);
  int update();
  int infect(int newn);
  bool is_stable();
};


class Population  {

private:
  int npeople;
  int immune;
  float prob;
  float probability;
  vector<Person> People;

public:
  void transfer(float probability);
  float set_probability_of_transfer();
  void number_immune();
  Population(int np);
  void print();
  int pop_update();
  void random_infection();
  int count_infected();
  void people_met(float probability, int pm);
  bool is_pop_stable();
};
