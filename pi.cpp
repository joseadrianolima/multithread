#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <future>
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
    promise<double> promise;

    auto do_calculation = [&](int terms)
    {
        try
        {
            auto result = calculate_pi(terms);
            promise.set_value(result);
        }
        catch (const exception &e)
        {
            promise.set_exception(current_exception());
        }
    };

    thread t1(do_calculation, 0);

    future<double> future = promise.get_future();

    t1.join();

    try
    {
        cout << setprecision(15) << future.get() << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}