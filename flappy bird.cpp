#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

const int SCREEN_WIDTH = 40;
const int SCREEN_HEIGHT = 20;
const char BIRD_CHAR = 'O';
const char PIPE_CHAR = '|';
const char SPACE_CHAR = ' ';
const char GROUND_CHAR = '_';

struct Bird {
    int x, y; // Position of the bird
};

struct Pipe {
    int x, gap_start, gap_height;
};

// Function to set terminal to non-blocking mode
void setNonBlockingMode(bool enable) {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    if (enable) {
        t.c_lflag &= ~ICANON;
        t.c_lflag &= ~ECHO;
        t.c_cc[VMIN] = 0;
        t.c_cc[VTIME] = 0;
    } else {
        t.c_lflag |= ICANON;
        t.c_lflag |= ECHO;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// Function to check if a key is pressed
char getKeyPress() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(STDIN_FILENO, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 0;
    old.c_cc[VTIME] = 1;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(STDIN_FILENO, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(STDIN_FILENO, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

void drawScreen(const Bird& bird, const std::vector<Pipe>& pipes, int score) {
    // Clear the screen
    std::system("clear");

    // Draw the screen
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            bool printed = false;

            // Draw pipes
            for (const auto& pipe : pipes) {
                if (j == pipe.x && (i < pipe.gap_start || i > pipe.gap_start + pipe.gap_height)) {
                    std::cout << PIPE_CHAR;
                    printed = true;
                    break;
                }
            }

            // Draw the bird
            if (!printed && j == bird.x && i == bird.y) {
                std::cout << BIRD_CHAR;
                printed = true;
            }

            // Draw empty space
            if (!printed) {
                std::cout << SPACE_CHAR;
            }
        }
        std::cout << '\n';
    }

    // Draw ground
    for (int j = 0; j < SCREEN_WIDTH; ++j) {
        std::cout << GROUND_CHAR;
    }
    std::cout << "\nScore: " << score << std::endl;
}

bool checkCollision(const Bird& bird, const std::vector<Pipe>& pipes) {
    if (bird.y >= SCREEN_HEIGHT || bird.y < 0) return true; // Bird hit the ground or flew too high
    for (const auto& pipe : pipes) {
        if (bird.x == pipe.x && (bird.y < pipe.gap_start || bird.y > pipe.gap_start + pipe.gap_height)) {
            return true; // Bird hit a pipe
        }
    }
    return false;
}

int main() {
    Bird bird = {5, SCREEN_HEIGHT / 2}; // Initial position of the bird
    std::vector<Pipe> pipes = {{SCREEN_WIDTH - 1, 5, 5}}; // Initial pipe
    int score = 0;
    bool isRunning = true;

    // Set terminal to non-blocking mode
    setNonBlockingMode(true);

    while (isRunning) {
        // Input handling
        char key = getKeyPress();
        if (key == ' ') { // Space bar to flap
            bird.y -= 2; // Move the bird up
        }

        // Gravity
        bird.y++;

        // Move pipes
        for (auto& pipe : pipes) {
            pipe.x--;
        }

        // Add new pipes
        if (pipes.back().x < SCREEN_WIDTH - 20) {
            int gap_start = rand() % (SCREEN_HEIGHT - 10);
            pipes.push_back({SCREEN_WIDTH - 1, gap_start, 5});
        }

        // Remove off-screen pipes
        if (pipes.front().x < 0) {
            pipes.erase(pipes.begin());
            score++;
        }

        // Draw screen
        drawScreen(bird, pipes, score);

        // Check for collisions
        if (checkCollision(bird, pipes)) {
            isRunning = false;
        }

        // Delay
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Slower game speed
    }

    // Restore terminal settings
    setNonBlockingMode(false);

    std::cout << "Game Over! Final Score: " << score << std::endl;
    return 0;
}
