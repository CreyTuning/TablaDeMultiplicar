#ifndef SCORE_H
#define SCORE_H

#include "qfile.h"
#include "qtextstream.h"

class Score
{
public:
    QFile * score_file;
    int score = 0;
    int completed = 0;

    Score();
    int getScore();
    void setScore(int score);
    int getCompleted();
    void setCompleted(int score);
    void update();
    void save();
};

#endif // SCORE_H
