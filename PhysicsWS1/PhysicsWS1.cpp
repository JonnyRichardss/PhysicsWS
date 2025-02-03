// PhysicsWS1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>

#include "StarMatrix.h"
#include "WordFunneling.h"
#include "DiceRolling.h"
#include "ScoreKeeping.h"
#include "RecurringCharacterCounter.h"
#include "GameOfLife.h"



static float PingPong(float t, float length) {
    t = fmod(t ,(length * 2));
    if (t > length) {
        return (length * 2) - t;
    }
    else {
        return t;
    }
}
static void RunStarMatrix() {
    printf("Enter Num lines:");
    //no input checking lol
    char input;
    std::cin >> input;
    input -= '0';
    int num = input;
    StarMatrix s;
    s.printSquare(num);
    printf("\n\n");
    s.printTriangle(num);
    printf("\n\n");
    s.printRandomBox();
    
}
static void RunWordFunnel() {
    std::string word1;
    std::string word2;
    printf("Main word:");
    std::cin >> word1;
    printf("\n");
    printf("Check word:");
    std::cin >> word2;
    printf("\n");
    WordFunneling w;
    if (w.WordFunnel(word1, word2)) printf("true\n");
    else printf("false\n");
    
}
static void RunDiceRoll() {
    std::string input;
    printf("input xDy:");
    std::cin >> input;
    DiceRolling d;
    d.Roll(input);
}
static void RunScoreKeeping() {
    std::string input;
    printf("input scores:");
    std::cin >> input;
    ScoreKeeping s;
    s.CalculateScore(input);
}
static void RunCharCounter() {
    std::string input;
    printf("input:");
    std::cin >> input;
    RecurringCharacterCounter r;
    r.printRecurringChar(input);
}
static void RunGameOfLife() {
    GameOfLife g;
    g.RunGame(true, false);
}
int main()
{
    srand(time(NULL));
    //RunStarMatrix();
    GameOfLife g;
    g.RunGame(false, false);
    //float a = PingPong(2, 5);
    //float b = PingPong(7, 5);
    //float c = PingPong(11, 5);
    //printf("A: %f, B: %f, C: %f", a, b, c);
    
}
