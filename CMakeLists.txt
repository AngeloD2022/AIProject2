cmake_minimum_required(VERSION 3.16)
project(AIProject2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/Users/angelodeluca/Qt/5.14.1/clang_64/lib/cmake")
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Core REQUIRED)

include_directories(.)
include_directories(NeuralNetworkLibrary)
set(SOURCE_FILES main.cpp)


add_executable(AIProject2
        NeuralNetworkLibrary/backpropagationworker.cpp
        NeuralNetworkLibrary/backpropagationworker.h
        NeuralNetworkLibrary/calc.cpp
        NeuralNetworkLibrary/calc.h
        NeuralNetworkLibrary/layer.cpp
        NeuralNetworkLibrary/layer.h
        NeuralNetworkLibrary/neuralnetwork.cpp
        NeuralNetworkLibrary/neuralnetwork.h
        AIProject2.pro
        main.cpp
        addvaluedialog.cpp
        addvaluedialog.h
        addvaluedialog.ui
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui)
target_link_libraries(AIProject2 Qt5::Core Qt5::Widgets Qt5::Gui)