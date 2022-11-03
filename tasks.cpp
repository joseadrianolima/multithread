#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <iomanip>
#include <exception>

using namespace std;

double calculate_pi(int terms)
{
    double sum = 0.0;

    if (terms < 1)
    {
        throw runtime_error("Terms can not be less then 1");
    }
    for (int i = 0; i < terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }
    return sum * 4;
}

int main()
{
    packaged_task<double(int)> task1(calculate_pi);

    future<double> future1 = task1.get_future();

    thread t1(ref(task1), 1E6);

    double result = future1.get();

    cout << setprecision(10) << result << endl;
    t1.join();

    return 0;
}