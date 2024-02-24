file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES}  "Utilities.cpp" "Movable.cpp" "NonMovable.cpp" "PlayerStatus.cpp" "Cat.cpp" "RandomCat.cpp" "SmartCat.cpp" "Mouse.cpp" "Board.cpp" "../include/FirstGift.h" "../include/SecondGift.h" "../include/ThirdGift.h")
