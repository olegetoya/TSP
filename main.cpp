#include <iostream>
#include "TSPParser.cpp"
#include "TSPSolver.cpp"

int main() {
    const std::string filename = "Resources/tsp_data.txt";
    TSPParser parser;
    auto points = parser.parse(filename);
    TSPSolver solver(points);
    solver.solve();
    std::cout << "Total distance: " << solver.getTotalDistance() << std::endl;
    std::cout << "Route: " << solver.getRouteString() << std::endl;
    solver.saveRoute("Resources/route.txt");
    return 0;
}
