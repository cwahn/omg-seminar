#ifndef STATE_MACHINE_HPP_
#define STATE_MACHINE_HPP_

enum class EdgeType
{
    Rising,
    Falling
};

struct State
{
    float motor_speed;
    unsigned long last_edge_time;
    int click_counter;
};

struct StateOutput
{
    State state;
    float motor_speed;
};

constexpr static unsigned long debounce_threshold = 50;
constexpr static unsigned long double_click_threshold = 500;
constexpr static unsigned long long_click_threshold = 2000;
constexpr static float max_motor_speed = 1.0f;
constexpr static float min_motor_speed = -1.0f;
constexpr static float speed_increment = 0.20f; // 20% increment

StateOutput update_motor_speed(const State &current_state, EdgeType edge, unsigned long current_time)
{
    State new_state = current_state;
    float new_motor_speed = current_state.motor_speed;

    unsigned long time_since_last_edge = current_time - new_state.last_edge_time;

    if (edge == EdgeType::Rising)
    {
        if (time_since_last_edge > debounce_threshold)
        {
            if (new_state.click_counter == 0)
            {
                new_motor_speed = std::min(max_motor_speed, new_motor_speed + speed_increment);
                new_state.click_counter = 1;
            }
            else if (time_since_last_edge < double_click_threshold)
            {
                new_motor_speed = std::max(min_motor_speed, new_motor_speed - speed_increment);
                new_state.click_counter = 0; // Reset counter after double click
            }
        }
    }
    else if (edge == EdgeType::Falling)
    {
        if (time_since_last_edge >= long_click_threshold)
        {
            new_motor_speed = 0.0f;      // Long press, set speed to zero
            new_state.click_counter = 0; // Reset counter after long click
        }
        else if (time_since_last_edge >= double_click_threshold && new_state.click_counter == 1)
        {
            new_state.click_counter = 0; // Not a double click, reset counter
        }
    }

    new_state.last_edge_time = current_time;
    return {new_state, new_motor_speed};
}

class MotorSpeedController
{
public:
    MotorSpeedController() : state_{0.0f, 0, 0} {}

    float react(EdgeType edge, unsigned long current_time)
    {
        StateOutput output = update_motor_speed(state_, edge, current_time);
        state_ = output.state;     // Update the internal state
        return output.motor_speed; // Return the new motor speed
    }

private:
    State state_; // Maintains the current state internally

    StateOutput update_motor_speed(const State &current_state, EdgeType edge, unsigned long current_time)
    {
        State new_state = current_state;
        float new_motor_speed = current_state.motor_speed;

        unsigned long time_since_last_edge = current_time - new_state.last_edge_time;

        if (edge == EdgeType::Rising)
        {
            if (time_since_last_edge > debounce_threshold)
            {
                if (new_state.click_counter == 0)
                {
                    new_motor_speed = std::min(max_motor_speed, new_motor_speed + speed_increment);
                    new_state.click_counter = 1;
                }
                else if (time_since_last_edge < double_click_threshold)
                {
                    new_motor_speed = std::max(min_motor_speed, new_motor_speed - speed_increment);
                    new_state.click_counter = 0; // Reset counter after double click
                }
            }
        }
        else if (edge == EdgeType::Falling)
        {
            if (time_since_last_edge >= long_click_threshold)
            {
                new_motor_speed = 0.0f;      // Long press, set speed to zero
                new_state.click_counter = 0; // Reset counter after long click
            }
            else if (time_since_last_edge >= double_click_threshold && new_state.click_counter == 1)
            {
                new_state.click_counter = 0; // Not a double click, reset counter
            }
        }

        new_state.last_edge_time = current_time;
        return {new_state, new_motor_speed};
    }
};

#endif // STATE_MACHINE_HPP_
