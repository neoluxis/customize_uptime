#include "iostream"
#include "sys/sysinfo.h"

using namespace std;

#define FMT "%d%c"

int getRealUp() {
  struct sysinfo info;
  sysinfo(&info);
  return info.uptime;
}

int main(int argc, char** argv) {
  int adder[] = {0,0,0,0,0,0}; // y, m, d, h, min, s
  char unit;
  for (int i=1;i<=6; i++) {
    if(argc>i) sscanf(argv[i], FMT, &adder[i-1], &unit);
  }
  int rt = getRealUp();

  int tmp;
  tmp = rt / (365 * 24 * 60 * 60);
  adder[0] += tmp;  
  rt -= tmp * 365 * 24 * 60 * 60;
  tmp = rt / (30 * 24 * 60 * 60);
  adder[1] += tmp;
  rt -= tmp * 30 * 24 * 60 * 60;
  tmp = rt / (24 * 60 * 60);
  adder[2] += tmp;
  rt -= tmp * 24 * 60 * 60;
  tmp = rt / (60 * 60);
  adder[3] += tmp;
  rt -= tmp * 60 * 60;
  tmp = rt / 60;
  adder[4] += tmp;
  rt -= tmp * 60;
  adder[5] += rt;

  cout << "up ";

  if (adder[0]) cout << adder[0] << " years ";
  if (adder[1]) cout << adder[1] << " months ";
  if (adder[2]) cout << adder[2] << " days ";
  if (adder[3]) cout << adder[3] << " hours ";
  if (adder[4]) cout << adder[4] << " minutes ";
  if (adder[5]) cout << adder[5] << " seconds ";
  cout << endl;
  
  return 0;
}
