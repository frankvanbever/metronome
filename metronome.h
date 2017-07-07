#ifndef METRONOME_H
#define METRONOME_H

#include <QWidget>
#include <QSound>

namespace Ui {
class Metronome;
}

class Metronome : public QWidget
{
    Q_OBJECT

public:
    explicit Metronome(QWidget *parent = 0);
    ~Metronome();

public slots:
    void on_sliderMoved(int position);
    void on_buttonPushed();

protected:
    void timerEvent(QTimerEvent *);


private:
    Ui::Metronome *ui;
    unsigned int bpm = 120;
    int timerId;
    QSoundEffect *effect;
    bool started = false;
};

#endif // METRONOME_H
