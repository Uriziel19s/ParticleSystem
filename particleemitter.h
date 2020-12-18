#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "multithreadoverseer.h"
#include "particledatacontainer.h"

class ParticleEmitter
{
public:
    ParticleEmitter(double emit_rate);
    void Emit(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager);

private:
    double emit_rate_;
};

#endif // PARTICLEEMITTER_H
