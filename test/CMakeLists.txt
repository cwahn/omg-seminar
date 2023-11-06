add_executable(omg-seminar-include test.cpp)
target_link_libraries(omg-seminar-include
    PRIVATE
    Catch2::Catch2WithMain
    omg-seminar
)