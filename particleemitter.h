#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "multithreadoverseer.h"
#include "particledatacontainer.h"
#include "particlegenerator.h"

class ParticleEmitter
{
public:
    ParticleEmitter(float emit_rate);
    virtual ~ParticleEmitter();
    virtual void Emit(float dt, ParticleDataContainer *p, MultithreadOverseer *task_menager);
    void AddGenerator(std::shared_ptr<ParticleGenerator> generator);
private:
    double emit_rate_;
protected:
    std::forward_list<std::shared_ptr<ParticleGenerator>> generators_;


};

#endif // PARTICLEEMITTER_H
