package com.example.jokehal;

// AIDL interface for Joke HAL
interface IJokeHal {
    /**
     * Returns a random joke as a String.
     */
    String getRandomJoke();
}
