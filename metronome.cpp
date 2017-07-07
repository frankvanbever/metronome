#include <QSoundEffect>
#include "metronome.h"
#include "ui_metronome.h"

Metronome::Metronome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Metronome),
    effect(new QSoundEffect)
{
    started = false;
    effect->setSource(QUrl::fromLocalFile("click.wav"));
    effect->setLoopCount(1);
    effect->setVolume(1.0);
    ui->setupUi(this);
    ui->bpmLabel->setNum((int) bpm);
    connect(ui->startStopButton, SIGNAL(clicked(bool)), this, SLOT(on_buttonPushed()));
    connect(ui->bpmSlider, SIGNAL(sliderMoved(int)), this, SLOT(on_sliderMoved(int)));
}

Metronome::~Metronome()
{
    delete ui;
}


void Metronome::on_buttonPushed()
{
        if(started == false){
            timerId = startTimer(60000 / bpm);
            ui->startStopButton->setText("Stop");
            started = true;
        } else {
            killTimer(timerId);
            ui->startStopButton->setText("Start");
            started = false;
        }
}


void Metronome::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    effect->play();
}

void Metronome::on_sliderMoved(int bpm)
{
    this->bpm = bpm;
    ui->bpmLabel->setNum(bpm);
    if (started == true) {
        killTimer(timerId);
        timerId = startTimer(60000 / bpm);
    }
}
