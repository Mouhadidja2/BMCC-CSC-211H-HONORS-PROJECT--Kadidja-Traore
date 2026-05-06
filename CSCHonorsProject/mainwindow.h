#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "backend/EcoStudent.h"
#include "backend/MissionManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    EcoStudent currentStudent;
    MissionManager missionManager;

    void loadMissionsToUI();
    void refreshHomepage();
    void refreshBadges();
    void refreshLeaderboard();
};

#endif // MAINWINDOW_H