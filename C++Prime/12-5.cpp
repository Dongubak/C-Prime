#include <iostream>
#include <cstdlib>
#include <ctime>
#include "12-5.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main(void) {

  using std::cin;
  using std::cout;
  using std::endl;
  using std::ios_base;
  std::srand(std::time(0));

  cout << "Case Study: Bank of Heather Automatic Teller\n";
  cout << "Enter maximum size of queue: ";
  int qs;
  cin >> qs;
  
  cout << "Enter the number of simulation hours: ";
  int hours;
  cin >> hours;
  long cyclelimit = MIN_PER_HR * hours;

  /*cout << "Enter the average number of customers per hour: ";*/
  double perhour = 1;
  /*cin >> perhour;*/


  while(true) {
    Queue line(qs);
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;
    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
      if (newcustomer(min_per_cust)) // have newcomer
      {
        if (line.isfull())
          turnaways++;
        else
        {
          customers++;
          temp.set(cycle); // cycle = time of arrival
          line.enqueue(temp); // add newcomer to line
        }
      }
      if (wait_time <= 0 && !line.isempty())
      {
        line.dequeue(temp); // attend next customer
        wait_time = temp.ptime(); // for wait_time minutes
        line_wait += cycle - temp.when();
        served++;
      }
      if (wait_time > 0)
        wait_time--;
      sum_line += line.queuecount();
    }

    if ((double)line_wait / served > 1) {
      // reporting results
      if (customers > 0)
      {
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << " turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);

        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
          << (double)line_wait / served << " minutes\n";
        cout << "customer per hour : " << min_per_cust * 60 << '\n';
      }
      else
        cout << "No customers!\n";

      break;
    }
    min_per_cust = MIN_PER_HR / ++perhour;
  }

  cout << "Done!\n";

  return 0;
}


bool newcustomer(double x)
{
  return (std::rand() * x / RAND_MAX < 1);
}