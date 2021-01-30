# CMakeList.txt : SFMLCMake の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.8)

# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable(SFMLTest main.cpp  "keyop.hpp")

# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
set(CMAKE_CXX_STANDARD 17)


## In most cases better set in the CMake cache
set(SFML_DIR "../SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(SFMLTest sfml-graphics sfml-window sfml-system)
