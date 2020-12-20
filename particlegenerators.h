#ifndef PARTICLEGENERATORS_H
#define PARTICLEGENERATORS_H
#include <random>

#include <glm/gtx/rotate_vector.hpp>
#include "particlegenerator.h"


class SpherePositionGenerator : public ParticleGenerator
{
public:
    float radius_{1};
    glm::vec3 center_{0.0f, 0.0f, 0.0f};

    SpherePositionGenerator() = default;
    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;
};

class OneColorGenerator : public ParticleGenerator
{
public:
    glm::vec3 color_{1.0f, 1.0f, 1.0f};

    OneColorGenerator() = default;
    void generate(double dt, ParticleDataContainer *p, MultithreadOverseer *task_menager, size_t start_id, size_t end_id) override;
};

#endif // PARTICLEGENERATORS_H
