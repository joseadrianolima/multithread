#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void work()
{
  for (int i = 0; i < 10; i++)
  {
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "work " << i << endl;
  }
}

void pause()
{
  for (int i = 100; i < 110; i++)
  {
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "pause " << i << endl;
  }
}

int main()
{
  thread t1(work);
  thread t2(pause);
  t1.join();
  t2.join();

  return 0;
}
