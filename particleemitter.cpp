#include "particleemitter.h"

ParticleEmitter::ParticleEmitter(double emit_rate) : emit_rate_(emit_rate)
{

}

void ParticleEmitter::Emit(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager)
{
//    const size_t kMaxNewParticles = static_cast<size_t>(dt * emit_rate_);
//    const size_t kStartId = p->count_alive_;
//    const size_t kEndId = std::min(kStartId + kMaxNewParticles, p->count_);

//    for(int i  = 0; i < task_menager->number_of_workers_; i++)
//    {
//        for(auto &gen : generators_)
//        {
//            gen.generate(dt, p, task_menager, kStartId, kEndId);
//        }
//    }
}
