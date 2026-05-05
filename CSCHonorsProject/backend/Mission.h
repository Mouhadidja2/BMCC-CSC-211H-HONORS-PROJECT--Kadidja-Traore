#ifndef MISSION_H
#define MISSION_H

#include <string>

class Mission {
protected:
    std::string title;
    int points;

public:
    Mission(std::string title, int points)
        : title(title), points(points) {}

    virtual ~Mission() {}

    virtual std::string getType() const = 0;

    std::string getTitle() const {
        return title;
    }

    int getPoints() const {
        return points;
    }
};

class RecyclingMission : public Mission {
public:
    RecyclingMission()
        : Mission("Recycle plastic or paper on campus", 3) {}

    std::string getType() const override {
        return "Recycling";
    }
};

class CleanupMission : public Mission {
public:
    CleanupMission()
        : Mission("Help clean a shared campus area", 5) {}

    std::string getType() const override {
        return "Cleanup";
    }
};

class VolunteerMission : public Mission {
public:
    VolunteerMission()
        : Mission("Volunteer for a green campus event", 10) {}

    std::string getType() const override {
        return "Volunteer";
    }
};

#endif // MISSION_H
