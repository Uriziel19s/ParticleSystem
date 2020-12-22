#ifndef PARTICLEUPDATERS_H
#define PARTICLEUPDATERS_H
#include <future>

#include <glm/gtx/rotate_vector.hpp>

#include <particleupdater.h>

class LawOfUniversalGravitationUpdater : public ParticleUpdater
{
public:
    float center_mass_ = 1.0f;
    glm::vec3 center_position_ = {0.0f, 0.0f, 0.0f};

    LawOfUniversalGravitationUpdater() { }
    ~LawOfUniversalGravitationUpdater() override { }
    void Update(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager) override;
private:
    void Calculate(float dt, ParticleDataContainer *p, size_t start_id, size_t end_id);
};

class NBodyUpdater : public ParticleUpdater
{
public:
    NBodyUpdater() { }
    ~NBodyUpdater() override {}
    void Update(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager) override;
private:
    void Calculate(float dt, ParticleDataContainer *p, size_t start_id, size_t end_id);
};

#endif // PARTICLEUPDATERS_H
