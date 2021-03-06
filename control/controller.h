#pragma once

#include "daisy_seed.h"
#include "knob.h"
#include "Spotykach.h"

class Controller {
public:
    Controller(daisy::DaisySeed& hw);
    ~Controller();

    void setPatrameters(vlly::spotykach::Spotykach& core);

private:
    static const int _knobsCount    = 4;
    std::array<Knob *, _knobsCount> _knobs;
    void initKnobs(daisy::DaisySeed& hw);
};