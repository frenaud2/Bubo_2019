#ifndef INTERNET_H
#define INTERNET_H
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
class Internet {
public:
    Internet();
    Internet(const Internet& orig);
    virtual ~Internet();
    int pinginternet();
    void testinternet();
private:
    FILE *output;

};

#endif /* INTERNET_H */

