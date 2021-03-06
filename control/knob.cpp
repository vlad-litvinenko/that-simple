#include "knob.h"

using namespace daisy;

Knob::Knob(AdcChannelConfig& conf, DaisySeed& hw, int channel): _channel(channel) {
    _channel = channel;
    auto usage = _usages[channel];
    conf.InitSingle(hw.GetPin(pin(usage)));
};

void Knob::charge(DaisySeed& hw, bool isLog = false) {
    float sr = hw.AudioSampleRate() / hw.AudioBlockSize();
    _ctrl.Init(hw.adc.GetPtr(_channel), sr);
    _param.Init(_ctrl, 0.f, 1.f, isLog ? daisy::Parameter::Curve::LOGARITHMIC : daisy::Parameter::Curve::LINEAR);
};

double Knob::value() { 
    _param.Process();
    return _param.Value(); 
};
