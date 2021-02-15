#ifndef SAFELOGGER_HPP_INCLUDED
#define SAFELOGGER_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

using namespace std;

class safeLogger{
public:

    safeLogger();

    safeLogger(string);

    void log(string, int);

    ofstream file;

    mutex safe;
};

#endif // SAFELOGGER_HPP_INCLUDED
