add_executable(seminar-test test.cpp)
target_link_libraries(seminar-test
    PRIVATE
    Catch2::Catch2WithMain
    # Catch2::Catch2
    seminar
)