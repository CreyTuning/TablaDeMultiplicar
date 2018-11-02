#include "score.h"

Score::Score()
{
    this->score_file = new QFile("score.dat");

    // Open o create score_file
    if(!this->score_file->exists())
    {
        this->score_file->open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream out(this->score_file);
        out << 0 << "\n" << 0;

        this->score_file->close();
    }

    else
    {
        this->update();
    }
}

void Score::update()
{
    this->score_file->open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(this->score_file);

    in >> this->score;
    in >> this->completed;

    this->score_file->close();
}

void Score::save()
{
    this->score_file->open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(this->score_file);
    out << this->score << "\n" << this->completed;

    this->score_file->close();
}

int Score::getScore()
{
    return this->score;
}

void Score::setScore(int score)
{
    this->score = score;
}

int Score::getCompleted()
{
    return this->completed;
}

void Score::setCompleted(int completed)
{
    this->completed = completed;
}
