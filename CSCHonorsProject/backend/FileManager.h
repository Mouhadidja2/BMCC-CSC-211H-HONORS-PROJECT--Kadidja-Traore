#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "EcoStudent.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <algorithm> // we use this for sorting for the leaderboard.

class FileManager {
public:

    // Save student data to file
    static void saveStudent(const EcoStudent& student) {
        std::ofstream file("students.txt", std::ios::app);

        if (!file) {
            throw std::runtime_error("Could not open students.txt for writing.");
        }

        file << student.getName() << ","
             << student.getEmail() << ","
             << student.getPoints() << "\n";

        file.close();
    }

    // Load and SORT leaderboard
    static std::vector<std::vector<std::string>> loadLeaderboard() {
        std::ifstream file("students.txt");

        if (!file) {
            throw std::runtime_error("Could not open students.txt for reading.");
        }

        std::vector<std::vector<std::string>> leaderboard;
        std::string line;

        // Read file line by line
        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string value;

            // Split by comma
            while (std::getline(ss, value, ',')) {
                row.push_back(value);
            }

            // Only add valid rows
            if (row.size() >= 3) {
                leaderboard.push_back(row);
            }
        }

        file.close();

        //  SORT BY POINTS (column index 2)
        std::sort(leaderboard.begin(), leaderboard.end(),
                  [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
                      int pointsA = std::stoi(a[2]);
                      int pointsB = std::stoi(b[2]);
                      return pointsA > pointsB; // descending order
                  }
                  );

        return leaderboard;
    }
};

#endif