#ifndef ECOSTUDENT_H
#define ECOSTUDENT_H

#include <string>
#include <vector>

class EcoStudent {
private:
    std::string name;
    std::string email;
    int points;
    std::vector<std::string> badges;
    std::vector<std::string> completedMissions;

public:
    EcoStudent()
        : name(""), email(""), points(0) {}

    EcoStudent(std::string name, std::string email)
        : name(name), email(email), points(0) {}

    void addPoints(int amount) {
        points += amount;
        updateBadges();
    }

    void completeMission(const std::string& missionTitle, int missionPoints) {
        completedMissions.push_back(missionTitle);
        addPoints(missionPoints);
    }

    void updateBadges() {
        if (points >= 3 && !hasBadge("Getting Started")) {
            badges.push_back("Getting Started");
        }

        if (points >= 10 && !hasBadge("Eco Superhero")) {
            badges.push_back("Eco Superhero");
        }

        if (points >= 20 && !hasBadge("Nature's GOAT")) {
            badges.push_back("Nature's GOAT");
        }
    }

    bool hasBadge(const std::string& badgeName) const {
        for (const std::string& badge : badges) {
            if (badge == badgeName) {
                return true;
            }
        }
        return false;
    }

    std::string getName() const {
        return name;
    }

    std::string getEmail() const {
        return email;
    }

    int getPoints() const {
        return points;
    }

    std::vector<std::string> getBadges() const {
        return badges;
    }

    std::vector<std::string> getCompletedMissions() const {
        return completedMissions;
    }

    void setPoints(int newPoints) {
        points = newPoints;
        updateBadges();
    }
};

#endif // ECOSTUDENT_H
