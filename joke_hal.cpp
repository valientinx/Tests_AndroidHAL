#include "joke_hal.h"
#include <vector>
#include <cstdlib>
#include <ctime>

JokeHal::JokeHal() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

std::string JokeHal::getRandomJoke() {
    static const std::vector<std::string> jokes = {
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "Why don't scientists trust atoms? Because they make up everything!",
        "I told my computer I needed a break, and it said 'No problem, I'll go to sleep.'",
        "Why do programmers prefer dark mode? Because light attracts bugs!"
    };
    int idx = std::rand() % jokes.size();
    return jokes[idx];
}
