#include "invalid_date.h"

using namespace std;

InvalidDate::InvalidDate(const char* msg) : runtime_error(msg) {}