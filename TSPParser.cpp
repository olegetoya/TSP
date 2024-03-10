#include <vector>
#include <fstream>
#include "BaseParser.cpp"

class TSPParser : public BaseParser {
public:
    std::vector<Point> parse(const std::string& filename) override {
        std::vector<Point> points;
        std::ifstream file(filename);
        int n;
        file >> n;
        double x, y;
        for (int i = 0; i < n; i++) {
            file >> x >> y;
            points.emplace_back(x, y);
        }
        return points;
    }
};
