#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "backend/InputValidator.h"
#include "backend/FileManager.h"

#include <QMessageBox>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet(
        "QMainWindow { background-color: #EAF7EA; }"
        "QWidget { background-color: #EAF7EA; font-family: Segoe UI; font-size: 14px; }"

        "QLabel { color: #1B4332; font-weight: bold; }"

        "QLineEdit {"
        " background-color: white;"
        " border: 2px solid #95D5B2;"
        " border-radius: 10px;"
        " padding: 8px;"
        "}"

        "QPushButton {"
        " background-color: #2D6A4F;"
        " color: white;"
        " border-radius: 12px;"
        " padding: 10px;"
        " font-weight: bold;"
        "}"

        "QPushButton:hover {FileManager::saveStudent(currentStudent);"
        " background-color: #40916C;"
        "}"

        "QListWidget, QTableWidget, QPlainTextEdit {"
        " background-color: white;"
        " border: 2px solid #95D5B2;"
        " border-radius: 10px;"
        " padding: 6px;"
        "}"
        );

    ui->stackedWidget->setCurrentWidget(ui->loginRegisterPage);

    loadMissionsToUI();

    connect(ui->loginButton, &QPushButton::clicked, this, [this]() {
        try {
            std::string name = ui->nameInput->text().toStdString();
            std::string email = ui->emailInput->text().toStdString();

            InputValidator::validateName(name);
            InputValidator::validateEmail(email);

            currentStudent = EcoStudent(name, email);

            ui->loginErrorLabel->setText("");
            refreshHomepage();

            ui->stackedWidget->setCurrentWidget(ui->homepagePage);
        }
        catch (const std::exception& e) {
            ui->loginErrorLabel->setText(e.what());
        }
    });

    connect(ui->missionsButton, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->missionsPage);
    });

    connect(ui->badgesButton, &QPushButton::clicked, this, [this]() {
        refreshBadges();
        ui->stackedWidget->setCurrentWidget(ui->badgesPage);
    });

    connect(ui->leaderboardButton, &QPushButton::clicked, this, [this]() {
        refreshLeaderboard();
        ui->stackedWidget->setCurrentWidget(ui->leaderboardPage);
    });

    connect(ui->backFromMissionsButton, &QPushButton::clicked, this, [this]() {
        refreshHomepage();
        ui->stackedWidget->setCurrentWidget(ui->homepagePage);
    });

    connect(ui->backFromBadgesButton, &QPushButton::clicked, this, [this]() {
        refreshHomepage();
        ui->stackedWidget->setCurrentWidget(ui->homepagePage);
    });

    connect(ui->backFromLeaderboardButton, &QPushButton::clicked, this, [this]() {
        refreshHomepage();
        ui->stackedWidget->setCurrentWidget(ui->homepagePage);
    });

    connect(ui->completeMissionButton, &QPushButton::clicked, this, [this]() {
        int selectedRow = ui->missionsListWidget->currentRow();

        if (selectedRow < 0) {
            QMessageBox::warning(this, "No Mission Selected", "Please select a mission first.");
            return;
        }

        auto missions = missionManager.getMissions();

        if (selectedRow >= static_cast<int>(missions.size())) {
            QMessageBox::warning(this, "Error", "Invalid mission selected.");
            return;
        }

        currentStudent.completeMission(
            missions[selectedRow]->getTitle(),
            missions[selectedRow]->getPoints()
            );

        try {
            FileManager::saveStudent(currentStudent);
        }
        catch (const std::exception& e) {
            QMessageBox::warning(this, "File Error", e.what());
        }

        refreshHomepage();
        refreshBadges();

        QMessageBox::information(this, "Mission Complete", "Points added successfully!");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadMissionsToUI()
{
    ui->missionsListWidget->clear();

    auto missions = missionManager.getMissions();

    for (const auto& mission : missions) {
        QString text = QString::fromStdString(
            mission->getType() + ": " +
            mission->getTitle() + " (" +
            std::to_string(mission->getPoints()) + " points)"
            );

        ui->missionsListWidget->addItem(text);
    }
}

void MainWindow::refreshHomepage()
{
    ui->welcomeLabel->setText(
        "Welcome, " + QString::fromStdString(currentStudent.getName())
        );

    ui->pointsLabel->setText(
        "Points: " + QString::number(currentStudent.getPoints())
        );
}

void MainWindow::refreshBadges()
{
    ui->badgesListWidget->clear();

    std::vector<std::string> badges = currentStudent.getBadges();

    if (badges.empty()) {
        ui->badgesListWidget->addItem("No badges yet. Complete missions to earn badges!");
        return;
    }

    for (const std::string& badge : badges) {
        ui->badgesListWidget->addItem(QString::fromStdString(badge));
    }
}

void MainWindow::refreshLeaderboard()
{
    ui->leaderboardTableWidget->setRowCount(0);
    ui->leaderboardTableWidget->setColumnCount(4);

    QStringList headers;
    headers << "Rank" << "Name" << "Email" << "Points";
    ui->leaderboardTableWidget->setHorizontalHeaderLabels(headers);

    try {
        std::vector<std::vector<std::string>> leaderboard = FileManager::loadLeaderboard();

        for (int i = 0; i < static_cast<int>(leaderboard.size()); i++) {
            ui->leaderboardTableWidget->insertRow(i);

            ui->leaderboardTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
            ui->leaderboardTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(leaderboard[i][0])));
            ui->leaderboardTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(leaderboard[i][1])));
            ui->leaderboardTableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(leaderboard[i][2])));
        }
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Leaderboard Error", e.what());
    }
}