#include <vector>
#include <string>
#include "Point.h"

class BaseSolver {
protected:
    std::vector<Point> points;

public:
    BaseSolver(const std::vector<Point>& pts) : points(pts) {}
    virtual void solve() = 0;
    virtual double getTotalDistance() const = 0;
    virtual std::string getRouteString() const = 0;
};
