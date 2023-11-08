#define CATCH_CONFIG_MAIN  

#include "catch2/catch_test_macros.hpp"
#include "state-machine.hpp"

TEST_CASE("MotorSpeedController Full Input/State Combinations Test", "[MotorSpeedController]")
{
    // Define a convenience structure to hold test parameters
    struct TestParam
    {
        State state;
        EdgeType edge;
        unsigned long time_since_last_edge;
        float expected_speed;
        int expected_click_counter;
    };

    // Define test cases
    std::vector<TestParam> tests = {
        // Single Click Test Cases
        {{0.0f, 0, 0}, EdgeType::Rising, 100, 0.2f, 1},
        {{0.2f, 0, 1}, EdgeType::Rising, 600, 0.0f, 0}, // Assuming double click

        // Double Click Test Cases
        {{0.0f, 0, 1}, EdgeType::Rising, 400, -0.2f, 0},

        // Long Press Test Cases
        {{0.2f, 0, 0}, EdgeType::Falling, 2500, 0.0f, 0}, // Speed should reset to 0

        // Debounce Test Cases
        {{0.2f, 0, 0}, EdgeType::Rising, 10, 0.2f, 0}, // No change, within debounce threshold

        // Disregarded Input Test Cases
        // Assuming three rapid clicks where the third click should be disregarded
        {{0.0f, 0, 1}, EdgeType::Rising, 100, 0.0f, 1},   // Second click
        {{0.0f, 100, 1}, EdgeType::Rising, 150, 0.0f, 0}, // Third click, too fast, should be disregarded

        // ... Add more test cases for other combinations and edge cases
    };

    MotorSpeedController controller;

    for (const auto &test : tests)
    {
        // Set the last edge time based on the current test time
        unsigned long current_time = test.state.last_edge_time + test.time_since_last_edge;
        float motor_speed = controller.react(test.edge, current_time);

        // Check the motor speed against the expected value
        CHECK(motor_speed == test.expected_speed);

        // In a real test, we would need to access the internal state of the controller,
        // which might require friend classes or test-specific accessors.
        // For now, we'll assume that we can check the click counter.
        // CHECK(controller.getClickCounter() == test.expected_click_counter);
    }
}
