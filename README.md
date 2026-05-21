# BMCC-CSC-211H-HONORS-PROJECT
"BMCC Green blue brown" would be a C++ Qt GUI application that turns sustainability into a structured game. Students log in, receive eco missions (recycling, planting, volunteering, reducing waste....), complete them to earn points, and unlock rewards such as badges. If they reach a certain amount of points or complete specific missions like volunteering to help clean the school, they could receive extra curricular credit. A leaderboard also to foster friendly competition. My solution uses gamification to help students build lasting sustainable habits. By completing eco friendly missions and seeing their impact, students become more aware and engaged in making the campus greener. Over time, this awareness and behavior change can extend beyond school, shaping them into citizens who understand how their daily choices affect the environment and who carry these positive habits into their society.


# Inspiration for Food4All
Many students are unaware of the environmental impact of their daily actions such as using single use plastics, food waste, improper recycling, excessive paper consumption and more . There is a lack of information, awareness, guidance, motivation, and a centralized platform to track and reward sustainable behavior to encourage students to be more green. This results in low engagement with campus environmental initiatives and missed opportunities for waste reduction.

# Project Description and usage
"BMCC Green blue brown" would be a C++ Qt GUI application that turns sustainability into a structured game. Students log in, receive eco missions (recycling, planting, volunteering, reducing waste....), complete them to earn points, and unlock rewards such as badges.

If they reach a certain amount of points or complete specific missions like volunteering to help clean the school, they could receive extra curricular credit. A leaderboard also to foster friendly competition. There is also a quiz they can learn with.

Link to video: https://youtu.be/9sm6ZlfbRvs




# Algorithm and Software Design of BMCC GREEN BLUE BROWN (UML)

https://excalidraw.com/#json=nopDgf22x8_D53FJzmdPb,9AEPYeceLaFWeYgWbxQl5g

# Challenges and solutions

Challenges:
Learning how to use the Qt framework and Qt Designer for building a multi-page GUI application. 
Connecting the backend C++ logic to the Qt GUI using signals, slots, and button interactions. 
Organizing the project into multiple files while maintaining clean and readable code.
Debugging build and compilation errors related to Qt setup, object names, and missing files.  
Solutions:
I learned how to use QStackedWidget to separate the interface into different pages such as Login/Register, Homepage, Missions, Badges, and Leaderboard. 
I used Qt’s connect() function so button clicks could trigger C++ functions, such as validating input, completing missions, updating points, and switching pages. 
I separated the project into specific files based on purpose, such as EcoStudent.h for student data, Mission.h for missions, FileManager.h for file handling, and mainwindow.cpp for GUI logic. 
I checked that all files were included in CMakeLists.txt, made sure object names in Qt Designer matched the code exactly, and fixed missing files such as main.cpp. 


# Accomplishments:

How to build a multi-page GUI application using the Qt framework and Qt Creator. How to connect frontend GUI components to backend C++ logic using Qt signals and slots. How gamification concepts can be applied to encourage environmental sustainability and user engagement. How UI/UX design choices affect the user experience of an application. How planning a project with wireframes and structured architecture improves development workflow.

# Future direction: 

Add more missions, questions, and improve the User interface.
