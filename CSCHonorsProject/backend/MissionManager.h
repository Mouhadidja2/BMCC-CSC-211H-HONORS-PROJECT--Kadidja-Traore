#ifndef MISSIONMANAGER_H
#define MISSIONMANAGER_H

#include "Mission.h"
#include "ObjectList.h"
#include <memory>

class MissionManager {
private:
    ObjectList<std::shared_ptr<Mission>> missions;

public:
    MissionManager() {
        missions.add(std::make_shared<RecyclingMission>());
        missions.add(std::make_shared<CleanupMission>());
        missions.add(std::make_shared<VolunteerMission>());
    }

    std::vector<std::shared_ptr<Mission>>& getMissions() {
        return missions.getAll();
    }
};

#endif // MISSIONMANAGER_H
