#include <vector>
#include <string>
#include "Point.h"

class BaseParser {
public:
    virtual std::vector<Point> parse(const std::string& filename) = 0;
};

