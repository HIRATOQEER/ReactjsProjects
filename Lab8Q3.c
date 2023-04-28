#include <iostream>
#include <thread>
#include <vector>
#include <fstream>

using namespace std;

void fibonacciGenerator(int n, vector<int>& fib)
{
    fib.push_back(0);
    if (n > 0) {
        fib.push_back(1);
    }

    for (int i = 2; i <= n; i++) {
        fib.push_back(fib[i-1] + fib[i-2]);
    }
}

int countEvenNumbers(vector<int> fib)
{
    int count = 0;
    for (int i = 0; i < fib.size(); i++) {
        if (fib[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int countOddNumbers(vector<int> fib)
{
    int count = 0;
    for (int i = 0; i < fib.size(); i++) {
        if (fib[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int calculateSum(vector<int> fib)
{
    int sum = 0;
    for (int i = 0; i < fib.size(); i++) {
        sum += fib[i];
    }
    return sum;
}

void printFibonacciSeries(vector<int> fib, int id)
{
    cout << "Thread " << id << " Fibonacci Series: ";
    for (int i = 0; i < fib.size(); i++) {
        cout << fib[i] << " ";
    }
    cout << endl;
}

void writeSumToFile(int sum, int id)
{
    ofstream outfile("sum.txt");
    outfile << "Thread " << id << " Sum of Fibonacci Series: " << sum << endl;
    outfile.close();
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <positive integer>" << endl;
        return 0;
    }

    int n = atoi(argv[1]);
    vector<int> fibonacciSeries;
    thread fibThread(fibonacciGenerator, n, ref(fibonacciSeries));
    fibThread.join();

    thread evenThread(countEvenNumbers, fibonacciSeries);
    thread oddThread(countOddNumbers, fibonacciSeries);
    thread sumThread(calculateSum, fibonacciSeries);

    int evenCount, oddCount, sum;

    evenThread.join();
    evenCount = evenThread.joinable() ? 0 : evenThread.get();

    oddThread.join();
    oddCount = oddThread.joinable() ? 0 : oddThread.get();

    sumThread.join();
    sum = sumThread.joinable() ? 0 : sumThread.get();

    printFibonacciSeries(fibonacciSeries, fibThread.get_id());
    cout << "Thread " << evenThread.get_id() << " Number of Even Numbers: " << evenCount << endl;
    cout << "Thread " << oddThread.get_id() << " Number of Odd Numbers: " << oddCount << endl;
    cout << "Thread " << sumThread.get_id() << " Sum of Fibonacci Series: " << sum << endl;

    writeSumToFile(sum, sumThread.get_id());

    return 0;
}

