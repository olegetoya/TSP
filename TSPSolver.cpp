#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "BaseSolver.cpp"

class TSPSolver : public BaseSolver {
private:
    std::vector<int> route;
    double totalDistance;

    double distance(const Point& p1, const Point& p2) {
        return std::hypot(p1.x - p2.x, p1.y - p2.y);
    }

    void calculateTotalDistance() {
        totalDistance = 0.0;
        for (size_t i = 0; i < route.size(); i++) {
            const auto& current = points[route[i]];
            const auto& next = points[route[(i + 1) % route.size()]];
            totalDistance += distance(current, next);
        }
    }

public:
    TSPSolver(const std::vector<Point>& pts) : BaseSolver(pts), totalDistance(std::numeric_limits<double>::max()) {
        route.resize(points.size());
        std::iota(route.begin(), route.end(), 0);
    }

    void solve() override {
        bool improved = true;
        while (improved) {
            improved = false;
            for (size_t i = 0; i < route.size() - 1; i++) {
                for (size_t j = i + 2; j < route.size(); j++) {
                    double delta = distance(points[route[i]], points[route[j]]) + distance(points[route[i + 1]], points[route[(j + 1) % route.size()]]) - distance(points[route[i]], points[route[i + 1]]) - distance(points[route[j]], points[route[(j + 1) % route.size()]]);
                    if (delta < 0) {
                        std::reverse(route.begin() + i + 1, route.begin() + j + 1);
                        improved = true;
                    }
                }
            }
        }

        calculateTotalDistance();
    }
    void saveRoute(const std::string& filename) const {
        std::ofstream outFile(filename);
        for (size_t i = 0; i < route.size(); ++i) {
            outFile << route[i]+1;
            if (i != route.size() - 1) outFile << " ";
        }
        outFile << std::endl;
    }

    double getTotalDistance() const override {
        return totalDistance;
    }

    std::string getRouteString() const override {
        std::ostringstream oss;
        for (size_t i = 0; i < route.size(); ++i) {
            oss << route[i] << (i < route.size() - 1 ? " -> " : "");
        }
        return oss.str();
    }
};